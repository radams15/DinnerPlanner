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

void Recipe_View::add_recipe_view_item(const char* title) {
    GtkListStore *store;
    GtkTreeIter iter;

    store = GTK_LIST_STORE(gtk_tree_view_get_model(recipe_view->gobj()));

    gtk_list_store_append(store, &iter);
    gtk_list_store_set(store, &iter, 0, title, -1);
}

void Recipe_View::init_recipe_view() {
    GtkCellRenderer *renderer;
    GtkTreeViewColumn *column;
    GtkListStore *store;

    renderer = gtk_cell_renderer_text_new();
    column = gtk_tree_view_column_new_with_attributes("Recipes", renderer, "text", 0, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(recipe_view->gobj()), column);

    store = gtk_list_store_new(1, G_TYPE_STRING);

    gtk_tree_view_set_model(GTK_TREE_VIEW(recipe_view->gobj()), GTK_TREE_MODEL(store));

    g_object_unref(store);
}

void Recipe_View::load_recipes() {
    for(Recipe r : db->get_recipes()){
        add_recipe_view_item(r.name.c_str());
    }
}
