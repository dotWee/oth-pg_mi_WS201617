#include <stdlib.h>
#include <stdio.h>

#include <gtk/gtk.h>

#define BUTTONS_ANZAHL 9
#define SPIELFELD 3

#define SPIELER_1 1
#define SPIELER_1_AKTIV "Spieler 1: Wähle ein Feld"

#define SPIELER_2 2
#define SPIELER_2_AKTIV "Spieler 2: Wähle ein Feld"

/**
 * GUI:
 *
 *
 * Menüleiste mit Titel als Status: Welcher Benutzer einen Button betätigen darf / wer gewonnen hat
 * ----------
 * Button0  Button1  Button2
 * Button3  Button4  Button5
 * Button6  Button7  Button8
 */

typedef struct _spielfeld {
    int spielfeld[SPIELFELD][SPIELFELD];
    int aktiverBenutzer;
} Spiel;

typedef struct _gui {
    GtkWidget *window;
    GtkWidget *grid;
    GtkWidget *buttons[BUTTONS_ANZAHL];

    Spiel *spiel;
} Gui;

void on_destroy(GtkWidget *src, gpointer data) {
    gtk_main_quit();
}

void on_update_title(Gui *gui) {
    printf("on_update_title\n");

    int aktiverSpieler = gui->spiel->aktiverBenutzer;
    if (aktiverSpieler == SPIELER_1) {
        gtk_window_set_title(GTK_WINDOW(gui->window), SPIELER_1_AKTIV);
    } else {
        gtk_window_set_title(GTK_WINDOW(gui->window), SPIELER_2_AKTIV);
    }
}

void on_button_click(GtkWidget *button, gpointer data) {
    Gui *gui = (Gui *) data;

    int aktiverBenutzer = gui->spiel->aktiverBenutzer;

    // Weiteren Klick darauf verbieten
    gtk_widget_set_sensitive(button, FALSE);

    // TODO Farbig markieren

    // Mit Text markieren
    gtk_button_set_label((GtkButton *) button, "X");

    // Aktiven Benutzer umdrehen: 1 zu 0 oder 0 zu 1
    gui->spiel->aktiverBenutzer = !aktiverBenutzer;

    // Fenstertitel aktualisieren
    on_update_title(gui);
}

void init_gui(Gui *gui) {
    gui->window = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    on_update_title(gui);

    gtk_window_set_default_size(GTK_WINDOW(gui->window), 450, 450);
    g_signal_connect(gui->window, "destroy", G_CALLBACK(on_destroy), NULL);

    gui->grid = gtk_grid_new();
    gtk_container_add(GTK_CONTAINER(gui->window), gui->grid);

    // 9 Buttons erstellen und in Array speichern
    // 3 Reihen...
    int buttonPosition = 0;
    for (int i = 0; i < 3; i += 1) {

        // 3 Buttons pro Reihe...
        for (int j = 0; j < 3; j += 1) {
            GtkWidget *button = gtk_button_new();
            gtk_widget_set_size_request(button, 150, 150);

            g_signal_connect(button, "clicked", G_CALLBACK(on_button_click), gui);

            gui->buttons[buttonPosition] = button;

            gtk_grid_attach(GTK_GRID (gui->grid), button, i, j, 1, 1);
            buttonPosition++;
        }
    }

    gtk_widget_show_all(gui->window);
}

int main(int argc, char *argv[]) {

    // GTK initialisieren
    gtk_init(&argc, &argv);

    // UI definieren
    Gui g;
    g.spiel = malloc(sizeof(Spiel));

    // Starte mit Spieler 1
    g.spiel->aktiverBenutzer = SPIELER_1;
    init_gui(&g);

    // UI starten
    gtk_main();

    return 0;
}