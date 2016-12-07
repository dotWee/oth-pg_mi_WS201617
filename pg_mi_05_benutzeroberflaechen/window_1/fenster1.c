#include <gtk/gtk.h>

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Hier kommt unser Fenstercode rein
    GtkWidget* window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Unser erstes Fenster");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gtk_widget_show(window);

    gtk_main();
    return 0;
}