//
// Created by rhys on 22/11/2020.
//

#include "Recipe_View.h"

Recipe_View::Recipe_View(int argc, char **argv) {

    db = new DB("../recipes.sqlite");

    app = Gtk::Application::create(argc, argv,URL);

    builder = Gtk::Builder::create_from_file(UI_FILE);

    builder->get_widget("main_window", window);

    if(!window){
        std::cerr << "WINDOW FAIL" << std::endl;
        exit(1);
    }

    builder->get_widget("recipe_view", recipe_view);

    window->set_default_size(WINDOW_SIZE);

    window->set_title(TITLE);

    init_recipe_view();
    load_recipes();

    window->show_all();
}

int Recipe_View::run() {
    return app->run(*window);
}

void Recipe_View::add_recipe_view_item(Recipe recipe) {
    Gtk::TreeModel::Row row = *recipe_store->append();

    row[recipe_cols.id] = recipe.id;
    row[recipe_cols.name] = recipe.name.c_str();
}

void Recipe_View::init_recipe_view() {
    recipe_store = Gtk::ListStore::create(recipe_cols);

    recipe_view->set_model(recipe_store);

    recipe_view->append_column("ID", recipe_cols.id);
    recipe_view->append_column("Name", recipe_cols.name);
}

void Recipe_View::load_recipes() {
    for(Recipe r : db->get_recipes()){
        add_recipe_view_item(r);
    }
}
