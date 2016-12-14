#include <gtk/gtk.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct _gui {
    GtkWidget *window;
    GtkWidget *table_layout;
    GtkWidget *entry;
    GtkWidget *label_entry;
    GtkWidget *label_result;
    GtkWidget *button;
} Gui;

// Hier mal als globale Variable um nochmal
// das Verhalten globaler Variablen zu veranschaulichen.
Gui g;

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

// Handler für den Klick auf den Berechnen-Button
void on_getquadrat(GtkWidget *src, gpointer data) {
    int zahl = atoi(gtk_entry_get_text(GTK_ENTRY(g.entry)));
    int erg = zahl * zahl;
    char buf[20];
    //itoa(erg, buf, 10);
    sprintf(buf, "%d", erg);
    gtk_label_set_text(GTK_LABEL(g.label_result), buf);
}

void init_gui() {
    g.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    gtk_window_set_title(GTK_WINDOW(g.window), "Berechne das Quadrat");
    gtk_window_set_default_size(GTK_WINDOW(g.window), 300, 300);
    g_signal_connect(g.window, "destroy", G_CALLBACK(on_destroy), NULL);
    g.table_layout = gtk_table_new(2, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(g.window), g.table_layout);

    g.label_entry = gtk_label_new("Zahl:");
    g.entry = gtk_entry_new();
    g.label_result = gtk_label_new("");
    g.button = gtk_button_new_with_label("Berechnen");

    gtk_table_attach_defaults(GTK_TABLE(g.table_layout), g.label_entry, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(g.table_layout), g.entry, 1, 2, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(g.table_layout), g.button, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(g.table_layout), g.label_result, 1, 2, 1, 2);

    gtk_widget_show_all(g.window);
}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);
    init_gui();
    // Könnte natürlich auch in init_gui registriert werden
    // hier nur als Beispiel, dass das überall geht!
    g_signal_connect(g.button, "clicked", G_CALLBACK(on_getquadrat), NULL);
    gtk_main();
    return 0;
}