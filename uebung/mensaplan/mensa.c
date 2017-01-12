#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <curl/curl.h>

// erforder sudo apt install libcurl3-dev

typedef struct _model {
    int num_blocks;
    // TODO: hier die Variablen einbauen, die der Parser braucht!
} Model;

// vgl. http://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string
size_t parse_to_list(char *ptr, size_t size, size_t number, Model *m) {
    // TODO: Schrittweise Lesen der Bytes...
    printf("%s\nGelesen mit parse_to_list\n", ptr);
    m->num_blocks += 1;
    return size * number;
}

// Main: Hauptbestandteil des Programms, lädt die Datei per HTTP herunter
int main(int argc, char *argv[]) {    
    CURL *curl = NULL;
    CURLcode res;
    char *format = "http://www.stwno.de/infomax/daten-extern/csv/HS-R-tag/%d.csv";
    int format_len = strlen(format);
    char url[format_len + 30]; // sollte reichen, da es keine ints gibt die länger als 29 Zeichen sind

    Model model;
    model.num_blocks = 0;

    if(argc != 2) {
        printf("Aufruf: %s [Kalenderwoche]\n", argv[0]);
        return 0;
    }

    memset(url, 0, format_len + 30);
    sprintf(url, format, atoi(argv[1]));

    curl = curl_easy_init();
    if(!curl) {
        printf("FEHLER: ...");
        exit(1);
    }

    curl_easy_setopt(curl, CURLOPT_URL, url);
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, parse_to_list);    
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &model);
    res = curl_easy_perform(curl);


    if(res != CURLE_OK) {
        printf("FEHLER: Download ht nicht funktioniert - %s", curl_easy_strerror(res));
        exit(2);
    }

    curl_easy_cleanup(curl);
    return 0;
}
