//
// Created by rhys on 29/12/2020.
//

#include <stdlib.h>

#include <sqlite3.h>

#include "recipes.h"
#include "db.h"

sqlite3* db;

int db_init(const char* path){
    return sqlite3_open(path, &db);
}

void db_close(){
    sqlite3_close(db);
}

int read_all_callback(void *data, int argc, char **argv, char ** col_name){
    recipe_callback callback = (recipe_callback*) data;

    Recipe* r = malloc(sizeof(Recipe));

    for(int i = 0; i<argc; i++){
        if(strcmp(col_name[i], "id") == 0){
            r->id = atoi(argv[i]);
        }else if(strcmp(col_name[i], "name") == 0){
            r->name = malloc( (strlen(argv[i])+1) * sizeof(char));
            strcpy(r->name, argv[i]);
        }else if(strcmp(col_name[i], "author") == 0){
            r->author = malloc( (strlen(argv[i])+1) * sizeof(char));
            strcpy(r->author, argv[i]);
        }else if(strcmp(col_name[i], "source") == 0){
            r->source = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->source, argv[i]);
        }
    }

    callback(r);

    return 0;
}

int read_specific_callback(void *data, int argc, char **argv, char ** col_name){
    Detailed_Recipe* r = (Detailed_Recipe*) data;

    for(int i = 0; i<argc; i++){
        if(strcmp(col_name[i], "id") == 0){
            r->id = atoi(argv[i]);
        }else if(strcmp(col_name[i], "name") == 0){
            r->name = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->name, argv[i]);
        }else if(strcmp(col_name[i], "author") == 0){
            r->author = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->author, argv[i]);
        }else if(strcmp(col_name[i], "source") == 0){
            r->source = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->source, argv[i]);
        }else if(strcmp(col_name[i], "description") == 0){
            r->description = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->description, argv[i]);
        }else if(strcmp(col_name[i], "image_url") == 0){
            r->image_url = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->image_url, argv[i]);
        }else if(strcmp(col_name[i], "category") == 0){
            r->category = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->category, argv[i]);
        }else if(strcmp(col_name[i], "ingredients") == 0){
            r->ingredients = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->ingredients, argv[i]);
        }else if(strcmp(col_name[i], "method") == 0){
            r->method = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->method, argv[i]);
        }else if(strcmp(col_name[i], "url") == 0){
            r->url = malloc((strlen(argv[i])+1) * sizeof(char));
            strcpy(r->url, argv[i]);
        }
    }

    return 0;
}

void get_recipes(recipe_callback r){
    int res = sqlite3_exec(db, "SELECT * FROM recipes", read_all_callback, r, 0);
}

Detailed_Recipe get_recipe(int id){
    Detailed_Recipe out;

    char* sql_template = "SELECT * FROM recipes WHERE id IS %d";
    char* sql = calloc(strlen(sql_template)+5, sizeof(char));

    sprintf(sql, sql_template, id);

    int res = sqlite3_exec(db, sql, read_specific_callback, &out, 0);

    return out;
}