#include <stdlib.h>
#include <stdio.h>
#include <gtk/gtk.h>

typedef struct _gui {
    GtkWidget *window;
    GtkWidget *layout;

    GtkWidget *label1;
    GtkWidget *eingabe1;

    GtkWidget *label2;
    GtkWidget *eingabe2;

    GtkWidget *label3;
    GtkWidget *eingabe3;

    GtkWidget *button;
} GuiModel;

GuiModel *gui_create() {
    GuiModel *guiModel = malloc(sizeof(GuiModel));

    // Neues Window definieren
    guiModel->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);

    // Neues Layout definieren
    guiModel->layout = gtk_table_new(4, 2, TRUE);
    gtk_container_add(GTK_CONTAINER(guiModel->window), guiModel->layout);

    // Labels setzen
    guiModel->label1 = gtk_label_new("Summand 1");
    guiModel->label2 = gtk_label_new("Summand 2");
    guiModel->label3 = gtk_label_new("Ergebnis");

    // Eingabefelder setzen
    guiModel->eingabe1 = gtk_entry_new();
    guiModel->eingabe2 = gtk_entry_new();
    guiModel->eingabe3 = gtk_entry_new();

    // Button setzen
    guiModel->button = gtk_button_new_with_label("Berechnen");

    // Titel setzen
    gtk_window_set_title(GTK_WINDOW(guiModel->window), "Aufgabe 2");

    // Fenstergröße setzen
    gtk_window_set_default_size(GTK_WINDOW(guiModel->window), 400, 400);

    return guiModel;
}

void gui_set_table_defaults(GuiModel *guiModel) {

    // Labels
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->label1, 0, 1, 0, 1);
    gtk_widget_show(guiModel->label1);

    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->label2, 0, 1, 1, 2);
    gtk_widget_show(guiModel->label2);
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->label3, 0, 1, 2, 3);
    gtk_widget_show(guiModel->label2);

    // Eingabe
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->eingabe1, 0, 1, 3, 4);
    gtk_widget_show(guiModel->eingabe1);
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->eingabe2, 0, 1, 4, 5);
    gtk_widget_show(guiModel->eingabe2);
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->eingabe3, 0, 1, 5, 6);
    gtk_widget_show(guiModel->eingabe3);

    // Button
    gtk_table_attach_defaults(GTK_TABLE(guiModel->layout), guiModel->label1, 0, 1, 6, 7);
    gtk_widget_show(guiModel->button);
}

void gui_show(GuiModel *guiModel) {
    gtk_widget_show(guiModel->label1);
    gtk_widget_show(guiModel->label2);
    gtk_widget_show(guiModel->label3);
    gtk_widget_show(guiModel->eingabe1);
    gtk_widget_show(guiModel->eingabe2);
    gtk_widget_show(guiModel->eingabe3);
    gtk_widget_show(guiModel->button);
    gtk_widget_show(guiModel->layout);
    gtk_widget_show(guiModel->window);

    gtk_main();
}

void gui_on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void gui_on_button_click(GtkWidget *src, gpointer data) {
    // Berechnung durchführen
    printf("on_button_click: Berechnung durchführen");
}

void gui_set_signals(GuiModel *guiModel) {
    g_signal_connect(guiModel->window, "destroy", G_CALLBACK(gui_on_destroy), NULL);

    g_signal_connect(guiModel->button, "clicked", G_CALLBACK(gui_on_button_click), NULL);

}

int main(int argc, char *argv[]) {
    gtk_init(&argc, &argv);

    // Neues UI erstellen
    GuiModel *guiModel = gui_create();

    // Button mit Funktionen verknüpfen
    gui_set_signals(guiModel);

    // Table defaults setzen
    gui_set_table_defaults(guiModel);

    // Gui anzeigen
    gui_show(guiModel);

    return 0;
}