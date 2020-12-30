//
// Created by rhys on 29/12/2020.
//

#ifndef BUILDDIR_RECIPES_H
#define BUILDDIR_RECIPES_H

#include "Recipe.h"

typedef struct{
    int length;
    Recipe* list;
} Recipe_List;

typedef void (*recipe_callback) (Recipe*);

int db_init(const char* path);
void db_close();

void get_recipes(recipe_callback r);
Detailed_Recipe get_recipe(int id);

#endif //BUILDDIR_RECIPES_H
