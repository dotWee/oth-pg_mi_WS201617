#include <gtk/gtk.h>
#include <stdio.h>

typedef struct _gui {
    GtkWidget* window;
    GtkWidget* layout;
    GtkWidget* button1;
    GtkWidget* button2;
    GtkWidget* label;
    GtkWidget* entry;
} GuiModel;

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void on_button_click(GtkWidget *src, gpointer data) {
    printf("Button wurde geklickt\n");
}

void on_button2_click(GtkWidget *src, gpointer data) {
    GuiModel* m = (GuiModel*)data;
    char* text = gtk_entry_get_text(GTK_ENTRY(m->entry));
    gtk_label_set_text(GTK_LABEL(m->label), text);
}
/*
void gui_create() {

}

void gui_register_handlers() {

}
*/
int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    GuiModel m;
    m.window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    m.layout = gtk_table_new(3,1, TRUE);
    m.button1 = gtk_button_new_with_label("Schließen2");
    m.button2 = gtk_button_new_with_label("Kopieren");
    m.label = gtk_label_new("Beschriftungstext");
    m.entry = gtk_entry_new();

    g_signal_connect(m.window, "destroy", G_CALLBACK(on_destroy), NULL);
    g_signal_connect(m.button1, "clicked", G_CALLBACK(on_button_click), NULL);
    g_signal_connect(m.button2, "clicked", G_CALLBACK(on_button2_click), &m);

    gtk_window_set_title(GTK_WINDOW(m.window), "Unser erstes Fenster");
    gtk_window_set_default_size(GTK_WINDOW(m.window), 400, 400);

    gtk_container_add(GTK_CONTAINER(m.window), m.layout);
    
    gtk_table_attach_defaults(GTK_TABLE(m.layout), m.button1, 0, 1, 0, 1);
    gtk_table_attach_defaults(GTK_TABLE(m.layout), m.button2, 0, 1, 1, 2);
    gtk_table_attach_defaults(GTK_TABLE(m.layout), m.label, 0, 1, 2, 3);
    gtk_table_attach_defaults(GTK_TABLE(m.layout), m.entry, 0, 1, 3, 4);

    gtk_widget_show(m.button1);
    gtk_widget_show(m.button2);
    gtk_widget_show(m.label);
    gtk_widget_show(m.entry);
    gtk_widget_show(m.layout);
    gtk_widget_show(m.window);

    gtk_main();
    return 0;
}