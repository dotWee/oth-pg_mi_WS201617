#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

#define STEP 15

typedef struct _gui {
    GtkWidget *window;
    GtkWidget *layout;
    GtkWidget *button_up;
    GtkWidget *button_down;
    GtkWidget *button_left;
    GtkWidget *button_right;
    GtkWidget *image;
    int x;
    int y;
} Gui;

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void on_up(GtkWidget *src, gpointer data) {
    Gui *g = (Gui*)data;
    if(g->y > 100) {
        g->y -= STEP;
        gtk_fixed_move(GTK_FIXED(g->layout), g->image, g->x, g->y);
    } 
}

void on_down(GtkWidget *src, gpointer data) {
    Gui *g = (Gui*)data;
    g->y += STEP;
    gtk_fixed_move(GTK_FIXED(g->layout), g->image, g->x, g->y);
}
void on_left(GtkWidget *src, gpointer data) {
    Gui *g = (Gui*)data;
    g->x -= STEP;
    gtk_fixed_move(GTK_FIXED(g->layout), g->image, g->x, g->y);
}
void on_right(GtkWidget *src, gpointer data) {
    Gui *g = (Gui*)data;
    g->x += STEP;
    gtk_fixed_move(GTK_FIXED(g->layout), g->image, g->x, g->y);
}

// Anlegen der Buttons, mit denen die Bewegungen des
// Bildes gesteuert werden sollen.
void init_control_area(Gui* g) {
    g->button_up = gtk_button_new_with_label("Oben");
    g->button_down = gtk_button_new_with_label("Unten");
    g->button_left = gtk_button_new_with_label("Links");
    g->button_right = gtk_button_new_with_label("Rechts");

    gtk_widget_set_size_request(g->button_up, 300, 30);
    gtk_widget_set_size_request(g->button_down, 300, 30);
    gtk_widget_set_size_request(g->button_left, 300, 30);
    gtk_widget_set_size_request(g->button_right, 300, 30);

    g_signal_connect(g->button_up, "clicked", G_CALLBACK(on_up), g);
    g_signal_connect(g->button_down, "clicked", G_CALLBACK(on_down), g);
    g_signal_connect(g->button_left, "clicked", G_CALLBACK(on_left), g);
    g_signal_connect(g->button_right, "clicked", G_CALLBACK(on_right), g);

    gtk_fixed_put(GTK_FIXED(g->layout), g->button_up, 150, 0);
    gtk_fixed_put(GTK_FIXED(g->layout), g->button_left, 0, 30);
    gtk_fixed_put(GTK_FIXED(g->layout), g->button_right, 300, 30);
    gtk_fixed_put(GTK_FIXED(g->layout), g->button_down, 150, 60);
}

void init_image_area(Gui* g) {
    g->image = gtk_image_new_from_file("./igel.jpg");
    g->x = 200;
    g->y = 150;
    gtk_fixed_put(GTK_FIXED(g->layout), g->image, g->x, g->y);   
}

void init_gui(Gui* g) {
    g->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(g->window), "Bild anzeigen");  
    gtk_window_set_default_size(GTK_WINDOW(g->window), 600, 600);  
    g_signal_connect(g->window, "destroy", G_CALLBACK(on_destroy), NULL);

    g->layout = gtk_fixed_new();
    gtk_container_add(GTK_CONTAINER(g->window), g->layout);
    
    init_control_area(g);
    init_image_area(g);

    gtk_widget_show_all(g->window);
}

int main(int argc, char *argv[]) {
    Gui g;
    gtk_init(&argc, &argv);
    init_gui(&g);  

    gtk_main();
    return 0;
}