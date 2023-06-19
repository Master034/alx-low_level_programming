#include "dog.h"
#include <stdlib.h>

/**
 * init_dog - Initializes a Struct of type dog
 * @d:Struct Dog
 * @name:Name Value
 * @age:dog Age
 * @owner:Owner
 */

void init_dog(struct dog *d, char *name, float age, char *owner)
{
	if (d == NULL)
		d = malloc(sizeof(struct dog));
	(*d).name = name;
	(*d).age = age;
	(*d).owner = owner;
}
