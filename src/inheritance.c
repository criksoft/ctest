#include <stdio.h>
#include <string.h>
#include <stddef.h>

struct animal {
    struct animal_ops *ops;
    int age;
};

struct animal_ops {
    void (*speak)(struct animal *self);
};

struct eater {
    struct eater_ops *ops;
    float calories_held;
};

struct eater_ops {
    void (*eat)(struct eater *self, float amount);
};

struct dog {
    struct dog_ops *ops;
    int age;
    struct eater eater_iface;
    char name[20];
};

struct dog_ops {
    struct animal_ops base;
    void (*eat)(struct dog *self);
};

void dog_speak(struct animal *self) {
    struct dog *dog = (struct dog *)self;
    printf("%s (Age: %d) says: Woof!\n", dog->name, dog->age);
}

void dog_eat(struct eater *self, float amount) {
    self->calories_held += amount;

    struct dog *d = (struct dog *)((char *)self - offsetof(struct dog, eater_iface));
    printf("%s ate %.1f cals. Total in belly: %.1f\n", d->name, amount, self->calories_held);
}

static struct dog_ops dog_vtable = { .base.speak = dog_speak };
static struct eater_ops dog_eater_vtable = { .eat = dog_eat };

struct dog new_dog(const char *name, int age) {
    struct dog d;
    d.ops = &dog_vtable;
    d.age = age;
    d.eater_iface.ops = &dog_eater_vtable;
    d.eater_iface.calories_held = 0;
    strncpy(d.name, name, 19);
    return d;
}

void perform_animal_duties(struct animal *a) {
    a->ops->speak(a);
}

void perform_eater_duties(struct eater *e) {
    e->ops->eat(e, 5);
}

int main() {
    struct dog my_dog = new_dog("Buddy", 5);

    struct animal *as_animal = (struct animal *)&my_dog;
    as_animal->age = 6;
    as_animal->ops->speak(as_animal);

    struct eater *as_eater = &my_dog.eater_iface;
    as_eater->ops->eat(as_eater, 500.5f);
    as_eater->ops->eat(as_eater, 200.2f);

    perform_animal_duties((struct animal *)&my_dog);

    perform_eater_duties(&my_dog.eater_iface);

    return 0;
}