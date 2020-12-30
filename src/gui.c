//
// Created by rhys on 29/12/2020.
//

#include "network.h"

#include "Recipe.h"
#include "recipes.h"

#include "gui.h"

#include "jsmn.h"

ResizeWidgets* image_widget;
GtkWidget* recipe_title;
GtkListStore* dish_store;
GtkListStore* ingredients_store;
GtkListStore* method_store;

void set_img(ResizeWidgets* widgets, const char* url){
    struct MemoryStruct data = get_url(url);

    GInputStream* img_stream = g_memory_input_stream_new_from_data(data.memory, data.size, NULL);
    GdkPixbuf* img_buf = gdk_pixbuf_new_from_stream(img_stream, NULL, NULL);

    widgets->pixbuf = img_buf;

    gtk_image_set_from_pixbuf(GTK_IMAGE(widgets->image), widgets->pixbuf);
}

gboolean resize_image(GtkWidget *widget, GdkRectangle *allocation, gpointer user_data) {
    GdkPixbuf* pxbscaled;
    GtkWidget* image = (GtkWidget *) ((ResizeWidgets *) user_data)->image;
    GdkPixbuf* pixbuf = (GdkPixbuf *) ((ResizeWidgets *) user_data)->pixbuf;

    if(pixbuf == NULL){
        return TRUE;
    }

    int x = 0;
    int y = 0;
    int h = allocation->height;
    int w = (gdk_pixbuf_get_width(pixbuf) * h) / gdk_pixbuf_get_height(pixbuf);

    pxbscaled = gdk_pixbuf_scale_simple(pixbuf, w, h, GDK_INTERP_BILINEAR);

    if (w < allocation->width) {
        x = (allocation->width - w) / 2;
        gtk_layout_move(GTK_LAYOUT(widget), image, x, y);
    }

    gtk_image_set_from_pixbuf(GTK_IMAGE(image), pxbscaled);

    g_object_unref (pxbscaled);

    return FALSE;
}

void set_recipe(Detailed_Recipe r){
    gtk_label_set_text(GTK_LABEL(recipe_title), r.name);
    set_img(image_widget, r.image_url);

    gtk_list_store_clear(GTK_LIST_STORE(method_store));
    gtk_list_store_clear(GTK_LIST_STORE(ingredients_store));

    jsmn_parser p;
    jsmn_init(&p);
    jsmntok_t t[64];
    int num_elems = jsmn_parse(&p, r.method, strlen(r.method), t, sizeof(t)/sizeof(t[0]));
    int i;

    GtkTreeIter iter;

    for(i=0 ; i<num_elems ; i++){ //https://github.com/zserge/jsmn/blob/053d3cd29200edb1bfd181d917d140c16c1f8834/example/simple.c#L67
        jsmntok_t *g = &t[i + 2];
        int str_len = g->end - g->start;
        char* data = calloc(str_len+1, sizeof(char));

        sprintf(data, "%.*s", str_len, r.method + g->start);

        if(strcmp(data, "") == 0) continue;

        gtk_list_store_append(method_store, &iter);
        gtk_list_store_set(method_store, &iter,
                           0, data,
                           -1
        );

        free(data);
    }

    num_elems = jsmn_parse(&p, r.ingredients, strlen(r.ingredients), t, sizeof(t)/sizeof(t[0]));
    printf("'%s'\n", r.ingredients);
    for(i=0 ; i<num_elems ; i++){
        jsmntok_t *g = &t[i + 2];
        int str_len = g->end - g->start;
        char* data = calloc(str_len+1, sizeof(char));

        sprintf(data, "%.*s", str_len, r.ingredients + g->start);
        printf(" %s\n", data);

        if(strcmp(data, "") == 0) continue;

        gtk_list_store_append(ingredients_store, &iter);
        gtk_list_store_set(ingredients_store, &iter,
                           0, data,
                           -1
        );

        free(data);
    }

    free_detailed_recipe(&r);
}

void add_recipe_list(Recipe* r){
    GtkTreeIter iter;

    gtk_list_store_append(dish_store, &iter);
    gtk_list_store_set(dish_store, &iter,
                        0, r->id,
                        1, r->name,
                        2, r->author,
                        -1
    );

    free_recipe(r);
}

void setup_dishes_tab(GtkWidget* tab){
    GtkWidget* view = gtk_tree_view_new();

    dish_store = gtk_list_store_new(3, G_TYPE_INT, G_TYPE_STRING, G_TYPE_STRING);

    GtkCellRenderer* renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                 -1,
                                                 "ID",
                                                 renderer,
                                                 "text", 0,
                                                 NULL
    );
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                -1,
                                                "Name",
                                                renderer,
                                                "text", 1,
                                                NULL
    );
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(view),
                                                -1,
                                                "Author",
                                                renderer,
                                                "text", 2,
                                                NULL
    );


    gtk_tree_view_set_model(GTK_TREE_VIEW(view), GTK_TREE_MODEL(dish_store));


    gtk_container_add(GTK_CONTAINER(tab), view);
}

void setup_specific_tab(GtkWidget* tab){
    recipe_title = gtk_label_new("Title");

    GtkWidget* image_container = gtk_layout_new(NULL, NULL);
    GtkWidget* image = gtk_image_new();

    image_widget = g_new0(ResizeWidgets, 1);
    image_widget->image = image;
    image_widget->pixbuf = NULL;

    g_signal_connect(GTK_CONTAINER(image_container), "size-allocate", G_CALLBACK(resize_image), image_widget);

    gtk_layout_put(GTK_LAYOUT(image_container), image, 0, 0);

    GtkWidget* specific_notebook = gtk_notebook_new();

    GtkWidget* ingredients_tab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* method_tab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    gtk_notebook_append_page(GTK_NOTEBOOK(specific_notebook), ingredients_tab, gtk_label_new("Ingredients"));
    gtk_notebook_append_page(GTK_NOTEBOOK(specific_notebook), method_tab, gtk_label_new("Method"));

    gtk_widget_set_vexpand(GTK_WIDGET(image), 1);

    gtk_container_add(GTK_CONTAINER(tab), recipe_title);
    gtk_container_add(GTK_CONTAINER(tab), image_container);
    gtk_container_add(GTK_CONTAINER(tab), specific_notebook);


    GtkWidget* ingredients_view = gtk_tree_view_new();
    ingredients_store = gtk_list_store_new(1, G_TYPE_STRING);
    GtkCellRenderer* ingredients_renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(ingredients_view),
                                                -1,
                                                "Ingredient",
                                                ingredients_renderer,
                                                "text", 0,
                                                NULL
    );

    GtkWidget* method_view = gtk_tree_view_new();
    method_store = gtk_list_store_new(1, G_TYPE_STRING);
    GtkCellRenderer* method_renderer = gtk_cell_renderer_text_new();
    gtk_tree_view_insert_column_with_attributes(GTK_TREE_VIEW(method_view),
                                                -1,
                                                "Step",
                                                method_renderer,
                                                "text", 0,
                                                NULL
    );

    gtk_tree_view_set_model(GTK_TREE_VIEW(ingredients_view), GTK_TREE_MODEL(ingredients_store));
    gtk_tree_view_set_model(GTK_TREE_VIEW(method_view), GTK_TREE_MODEL(method_store));

    gtk_container_add(GTK_CONTAINER(ingredients_tab), ingredients_view);
    gtk_container_add(GTK_CONTAINER(method_tab), method_view);

    get_recipes(add_recipe_list);

    set_recipe(get_recipe(105));
}

void activate(GtkApplication* app, gpointer user_data){
    GtkWidget *window = gtk_application_window_new(app);

    GtkWidget* header = gtk_header_bar_new();
    gtk_header_bar_set_show_close_button(GTK_HEADER_BAR(header), 1);
    gtk_window_set_titlebar(GTK_WINDOW(window), GTK_WIDGET(header));

    GtkWidget* notebook = gtk_notebook_new();

    GtkWidget* dishes_tab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);
    GtkWidget* specific_tab = gtk_box_new(GTK_ORIENTATION_VERTICAL, 0);

    setup_dishes_tab(dishes_tab);
    setup_specific_tab(specific_tab);

    GtkWidget* dishes_scroll = gtk_scrolled_window_new(0, 0);
    GtkWidget* specific_scroll = gtk_scrolled_window_new(0, 0);

    gtk_container_add(GTK_CONTAINER(dishes_scroll), dishes_tab);
    gtk_container_add(GTK_CONTAINER(specific_scroll), specific_tab);

    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), dishes_scroll, gtk_label_new("Dishes"));
    gtk_notebook_append_page(GTK_NOTEBOOK(notebook), specific_scroll, gtk_label_new("Specific"));

    gtk_container_add(GTK_CONTAINER(window), notebook);

    gtk_window_set_title(GTK_WINDOW (window), "Dinner Planner");
    gtk_window_set_default_size(GTK_WINDOW (window), 600, 400);

    gtk_widget_show_all(window);

    gtk_notebook_set_current_page(GTK_NOTEBOOK(notebook), 0);
}