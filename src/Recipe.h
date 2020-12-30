//
// Created by rhys on 29/12/2020.
//

#ifndef BUILDDIR_RECIPE_H
#define BUILDDIR_RECIPE_H

typedef struct{
    int id;
    char* name;
    char* author;
    char* source;
} Recipe;

typedef struct {
    int id;
    char* name;
    char* author;
    char* description;
    char* image_url;
    char* category;
    char* ingredients;
    char* method;
    char* url;
    char* source;
} Detailed_Recipe;

static inline void free_recipe(Recipe* r){
    free(r->name);
    free(r->author);
    free(r->source);
}

static inline void free_detailed_recipe(Detailed_Recipe* r){
    free(r->name);
    free(r->author);
    free(r->source);
    free(r->description);
    free(r->image_url);
    free(r->category);
    free(r->ingredients);
    free(r->method);
    free(r->url);
}

#endif //BUILDDIR_RECIPE_H
