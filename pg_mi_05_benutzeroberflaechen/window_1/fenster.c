#include <gtk/gtk.h>
#include <stdio.h>

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void on_button_click(GtkWidget *src, gpointer data) {
    printf("Button wurde geklickt\n");
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Hier kommt unser Fenstercode rein
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    GtkWidget* button;
    button = gtk_button_new_with_label("Schließen2");

    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(button, "clicked", G_CALLBACK(on_button_click), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Unser erstes Fenster");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gtk_container_add(GTK_CONTAINER(window), button);

    gtk_widget_show(button);
    gtk_widget_show(window);

    gtk_main();
    return 0;
}