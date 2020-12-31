//
// Created by rhys on 22/11/2020.
//

#include "DB.h"

int get_recipes_callback(void* data, int argc, char** argv, char** col_name){
    std::vector<Recipe>* out = (std::vector<Recipe>*) data;

    Recipe recipe;

    for(int i=0 ; i<argc ; i++){
        if(strcmp(col_name[i], "id") == 0){
            recipe.id = atoi(argv[i]);
        }else if(strcmp(col_name[i], "name") == 0){
            recipe.name = argv[i];
        }else if(strcmp(col_name[i], "author") == 0){
            recipe.author = argv[i];
        }else if(strcmp(col_name[i], "description") == 0){
            recipe.description = argv[i];
        }else if(strcmp(col_name[i], "image_url") == 0){
            recipe.image_url = argv[i];
        }else if(strcmp(col_name[i], "category") == 0){
            recipe.category = argv[i];
        }else if(strcmp(col_name[i], "ingredients") == 0){
            recipe.ingredients = argv[i];
        }else if(strcmp(col_name[i], "method") == 0){
            recipe.method = argv[i];
        }else if(strcmp(col_name[i], "url") == 0){
            recipe.url = argv[i];
        }
    }

    out->push_back(recipe);

    return 0;
}

DB::DB(const char *path) {
    sqlite3_open(path, &this->db);
}

DB::~DB() {
    sqlite3_close(this->db);
}

std::vector<Recipe> DB::get_recipes() {
    std::vector<Recipe> out;

    sqlite3_exec(this->db, "SELECT * FROM recipes", get_recipes_callback, &out, NULL);

    return out;
}
