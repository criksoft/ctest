#include <stddef.h>
#include <stdio.h>
#include <string.h>

#define container_of(ptr, type, member) ((type *)((char *)(ptr) - offsetof(type, member)))

struct speaker {
    struct speaker_ops *ops;
};

struct speaker_ops {
    void (*speak)(struct speaker *self);
};

struct eater {
    struct eater_ops *ops;
};

struct eater_ops {
    void (*eat)(struct eater *self);
};

struct dog {
    struct speaker speaker;
    struct eater eater;
    char name[20];
};

struct channel_dog {
    struct speaker speaker;
    struct eater eater;
    char name[20];
};

void dog_speak(struct speaker *self)
{
    struct dog *dog = container_of(self, struct dog, speaker);
    printf("My name is %s and I'm speaking!\n", dog->name);
}

void channel_speak(struct speaker *self)
{
    struct dog *dog = container_of(self, struct dog, speaker);
    printf("wooooof!!\n");
}

void dog_eat(struct eater *self)
{
    struct dog *dog = container_of(self, struct dog, eater);
    printf("My name is %s and I'm eating!\n", dog->name);
}

struct speaker_ops channel_speaker_ops = {.speak = channel_speak};

struct speaker_ops dog_speaker_ops = {.speak = dog_speak};

struct eater_ops dog_eater_ops = {.eat = dog_eat};

struct dog new_dog(const char *name)
{
    struct dog dog = {
        .speaker.ops = &dog_speaker_ops,
        .eater.ops = &dog_eater_ops,
    };
    strncpy(dog.name, name, sizeof(dog.name) - 1);
    dog.name[sizeof(dog.name) - 1] = '\0';
    return dog;
}

struct channel_dog new_channel(const char *name)
{
    struct channel_dog dog = {
        .speaker.ops = &channel_speaker_ops,
        .eater.ops = &dog_eater_ops,
    };
    strncpy(dog.name, name, sizeof(dog.name) - 1);
    dog.name[sizeof(dog.name) - 1] = '\0';
    return dog;
}

void get_the_speaker_to_speak(struct speaker *speaker)
{
    speaker->ops->speak(speaker);
}

void get_the_eater_to_eat(struct eater *eater)
{
    eater->ops->eat(eater);
}

int main()
{
    struct dog dog = new_dog("Buddy");
    struct channel_dog channel = new_channel("Channel");

    get_the_speaker_to_speak(&channel.speaker);
    get_the_speaker_to_speak(&dog.speaker);

    get_the_eater_to_eat(&dog.eater);

    dog.speaker.ops->speak(&dog.speaker);
    dog.eater.ops->eat(&dog.eater);

    return 0;
}
