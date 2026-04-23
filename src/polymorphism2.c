#include <stddef.h>
#include <stdio.h>
#include <string.h>

struct speaker_ops {
    void (*speak)(struct speaker_ops **self);
};

struct eater_ops {
    void (*eat)(struct eater_ops **self);
};

struct dog {
    struct speaker_ops *speaker;
    struct eater_ops *eater;
    char name[20];
};

void dog_speak(struct speaker_ops **self)
{
    struct dog *dog = (struct dog *)((char *)self - offsetof(struct dog, speaker));
    printf("My name is %s and I'm speaking!\n", dog->name);
}

void dog_eat(struct eater_ops **self)
{
    struct dog *dog = (struct dog *)((char *)self - offsetof(struct dog, eater));
    printf("My name is %s and I'm eating!\n", dog->name);
}

struct speaker_ops dog_speaker_ops = {.speak = dog_speak};

struct eater_ops dog_eater_ops = {.eat = dog_eat};

struct dog new_dog(const char *name)
{
    struct dog dog = {
        .speaker = &dog_speaker_ops,
        .eater = &dog_eater_ops,
    };
    strncpy(dog.name, name, sizeof(dog.name) - 1);
    dog.name[sizeof(dog.name) - 1] = '\0';
    return dog;
}

void get_the_speaker_to_speak(struct speaker_ops **speaker)
{
    (*speaker)->speak(speaker);
}

void get_the_eater_to_eat(struct eater_ops **eater)
{
    (*eater)->eat(eater);
}

int main()
{
    struct dog dog = new_dog("Buddy");

    get_the_speaker_to_speak(&dog.speaker);
    get_the_eater_to_eat(&dog.eater);

    dog.speaker->speak(&dog.speaker);
    dog.eater->eat(&dog.eater);

    return 0;
}