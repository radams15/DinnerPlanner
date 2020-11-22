//
// Created by rhys on 22/11/2020.
//

#include "Recipe_View.h"

string lower(string str){
    string b = str;
    transform(b.begin(), b.end(), b.begin(), ::tolower);
    return b;
}

Recipe_View::Recipe_View(int argc, char **argv) {

    db = new DB("../recipes.sqlite");

    app = Gtk::Application::create(argc, argv,URL);

    builder = Gtk::Builder::create_from_file(UI_FILE);

    builder->get_widget("main_window", window);

    if(!window){
        std::cerr << "WINDOW FAIL" << std::endl;
        exit(1);
    }

    builder->get_widget("search_bar", search_bar);

    search_bar->signal_changed().connect(sigc::mem_fun(*this, &Recipe_View::search_changed));

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

    recipe_view->signal_row_activated().connect(sigc::mem_fun(*this, &Recipe_View::recipe_click_callback));
}

void Recipe_View::load_recipes() {
    recipes = db->get_recipes();
    for(Recipe r : recipes){
        add_recipe_view_item(r);
    }
}

void Recipe_View::recipe_click_callback(Gtk::TreePath a, Gtk::TreeViewColumn* b) {
    int id = atoi(a.to_string().c_str());

    Recipe recipe = recipes[id];

    printf("%s by %s\n", recipe.name.c_str(), recipe.author.c_str());
}

void Recipe_View::search_changed() {
    string text = search_bar->get_text();

    recipe_view_clear();

    for(Recipe r : recipes){
        if(lower(r.name).find(lower(text)) != string::npos) {
            add_recipe_view_item(r);
        }
    }
}

void Recipe_View::recipe_view_clear() {
    GtkTreeIter iter;
    while(true) {
        if(gtk_tree_model_iter_nth_child(GTK_TREE_MODEL(recipe_store->gobj()), &iter, NULL, 0)) {
            gtk_list_store_remove(recipe_store->gobj(), &iter);
        }else{
            break;
        }
    }
}
