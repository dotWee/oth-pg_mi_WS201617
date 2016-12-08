#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

/*
 * Eine Lösung eines Teilnehmers/einer Teilnehmerin, die ich um einige Kommentare ergänzt habe.
 *
 * Anmerkung: Rein vom Algorithmus her eine richtig gute Idee mit verschiedenen kleinen
 *            Umsetzungs-Schwächen -> Weiter so, das ist der richtige Weg Programmieren zu lernen ;-)
 */
int main(int argc, char *argv[]) {
	char *result = NULL;
	if(argc != 4) {
		printf("Korrekter Aufruf: %s \"string to replace\" \"replacement\" \"String\"\n", argv[0]);
		return 0;
	}

	int word_1_len = strlen(argv[1]);
    // Bitte mit + 1 (ist aber nicht die Ursache des Fehlers)
	char word_1[word_1_len+1];

	int word_2_len = strlen(argv[2]);
    // Bitte mit + 1 (ist aber nicht die Ursache des Fehlers)
	char word_2[word_2_len+1];

	int str_len = strlen(argv[3]);
	int counter;

	result = (char *)malloc(sizeof(char)*100);

    // Bitte strncpy (auch wenn strcpy hier richtig funktioniert)
	strncpy(word_1, argv[1], word_1_len);
	strncpy(word_2, argv[2], word_2_len);

    // Die Stelle von der gelesen wird kann eine andere sein als die,
    // an der in result geschrieben wird.
    int read = 0;

    // Anmerkung: i < str_len funktioniert nur, wenn word_1 und word_2 gleich
    //            lang sind.
	for(int i = 0; i < str_len; i++, read++) {
		if(argv[3][i] == word_1[0]) {
			counter = read;
			_Bool x = true;
			for(int a = 0; a < word_1_len; a++) {
				if(argv[3][counter] == word_1[a]) {
					counter++;
				}else{
					x = false;
					break;
				}
			}
			if(x == true) {
				for(int b = 0; b < word_2_len; b++) {
					result[i] = word_2[b];
					i++;
				}
                // Hier wird sonst eine Stelle übersprungen 
                // (also bleibt sonst ein \0 mitten im result)
                i--;
                // Die Lesestelle anpassen
                read += word_1_len - 1;
			}
            // Fehler: hier fehlte das else, so wurde immer ein Zeichen übersprungen, wenn
            //         ein Wort gleich dem gesuchten String begonnen hat.
            else {
                result[i] = argv[3][read];
            } 
		} else {
			result[i] = argv[3][read];
		}
	}


	if(result != NULL) {
		printf("Ergebnis: %s\n", result);
	}
	free(result);
	return 0;
}
