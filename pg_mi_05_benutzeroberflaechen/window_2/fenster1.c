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
    GtkWidget* layout = gtk_table_new(3,1, TRUE);
    GtkWidget* button1 = gtk_button_new_with_label("Schließen2");
    GtkWidget* button2 = gtk_button_new_with_label("Schließen3");
    GtkWidget* button3 = gtk_button_new_with_label("Schließen4");

    g_signal_connect(window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(button1, "clicked", G_CALLBACK(on_button_click), NULL);

    gtk_window_set_title(GTK_WINDOW(window), "Unser erstes Fenster");
    gtk_window_set_default_size(GTK_WINDOW(window), 400, 400);

    gtk_container_add(GTK_CONTAINER(window), layout);
    
    gtk_table_attach_defaults(GTK_TABLE(layout), button1, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(layout), button2, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(layout), button3, 0, 1, 2, 3);

    gtk_widget_show(button1);
    gtk_widget_show(button2);
    gtk_widget_show(button3);
    gtk_widget_show(layout);
    gtk_widget_show(window);

    gtk_main();
    return 0;
}