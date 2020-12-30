//
// Created by rhys on 29/12/2020.
//

#ifndef BUILDDIR_GUI_H
#define BUILDDIR_GUI_H

#include <gtk/gtk.h>

#include "network.h"

#include "Recipe.h"
#include "recipes.h"

typedef struct{
    GtkWidget *image;
    GdkPixbuf *pixbuf;
} ResizeWidgets;

void activate(GtkApplication* app, gpointer user_data);

#endif //BUILDDIR_GUI_H
