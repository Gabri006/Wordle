#ifndef LIB_H
#define LIB_H

/* costante per il numero di tentativi, usata diminuita di 1 per il numero di lettere della parola */
#define MAXTRY 6

/* procedura per prendere una parola dall'elenco dato, la parola sara' quella da indovinare */
void randomWord(char mat[][MAXTRY], char *indovina);

/* procedura per colorare di verde le lettere messe nella posizione corretta */
void checkLetterGreen(char indovina, char parolaInput);

/* procedura per colorare di giallo le lettere messe nella posizione errata ma presenti nella parola da indovinare */
void checkLetterYellow(char *indovina, char parolaInput[][MAXTRY], int pos, int *cont, int k);

/* procedura per stampare la taella con le parole inserite in input */
void stampaTabella(char *indovina, char parolaInput[][MAXTRY], int c, int *cont, int *tmp);

#endif // LIB_H
