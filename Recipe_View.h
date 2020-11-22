//
// Created by rhys on 22/11/2020.
//

#ifndef DINNERPLANNER_GUI_RECIPE_VIEW_H
#define DINNERPLANNER_GUI_RECIPE_VIEW_H

#include <gtkmm.h>
#include <iostream>

#include "DB.h"

#define UI_FILE "../recipe_view.glade"
#define TITLE "Recipe Finder"
#define URL "org.rhys.RecipeFinder"
#define WINDOW_SIZE 400, 500

class Recipe_View {
private:
    Glib::RefPtr<Gtk::Builder> builder;
    Gtk::Window* window;
    Glib::RefPtr<Gtk::Application> app;

    DB* db;

    Gtk::TreeView* recipe_view;

    void add_recipe_view_item(const char* title);

    void init_recipe_view();

    void load_recipes();

public:
    Recipe_View(int argc, char** argv);

    int run();
};


#endif //DINNERPLANNER_GUI_RECIPE_VIEW_H
