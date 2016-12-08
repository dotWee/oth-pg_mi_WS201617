#include <stdio.h>
#include <stdlib.h>
#include <gtk/gtk.h>

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void on_button_click(GtkWidget *src, gpointer data) {
    printf("Hallo Benutzer\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Hier kommt unser Fenstercode rein
    GtkWidget *window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget *button;
    button = gtk_button_new_with_label("Sag Hallo");

    // Zeige bei einem destroy signal auf die on_destroy Funktion
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    // Führe on_button_click Funktion aus wenn der Benutzer auf den Button klickt
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_click), NULL);

    // Titel setzen
    gtk_window_set_title(GTK_WINDOW(window), "Aufgabe 1");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gtk_container_add(GTK_CONTAINER(window), button);

    // Widgets anzeigen
    gtk_widget_show(button);
    gtk_widget_show(window);
    gtk_main();

    return 0;
}