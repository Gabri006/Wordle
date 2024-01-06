#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "lib.h"
#include "conio.h"

void randomWord (char mat[][MAXTRY], char *indovina)
{
    int num = 0;

    /*prende un numero casuale da 0 a 3006*/
    num = rand () % 3003;
    /*copia in indovina la parola scelta tra la lista di parole*/
    strcpy (indovina, mat[num]);
}

void checkLetterGreen (char indovina, char parolaInput)
{
    /*se le lettere di indovina e parolaInpuit sono uguali e nella stessa posizione, allora le colora di verde*/
    if (indovina == parolaInput) {
        textcolor (LIGHTGREEN);
    }
}

void checkLetterYellow (char *indovina, char parolaInput[][MAXTRY], int pos, int *cont, int k)
{
    int i = 0, j = 0, flag = 0;

    /* decrementa la frequenza di una lettera se la lettera della parola da indovinare e' uguale a quella della parola inserita e le lettere sono nella stessa posizione e se la lettera che deve essere stampata e' quella che deve essere decrementata */
    for (i = 0; i < MAXTRY - 1; i++) {
        for (j = 0; j < MAXTRY - 1; j++) {
            if (indovina[i] == parolaInput[k][j] && i == j && flag == 0 && indovina[i] == parolaInput[k][pos]) {
                cont[parolaInput[k][j] - 97] -= 1;
                flag = 1;
            }
        }
    }

    flag = 0;

    /* se viene trovata una corrispondenza il contatore della lettera in questione viene decrementato, se e' a 0 significa che la lettera non c'e' o che sono state esaurite per la parola inserita */
    for (i = 0; i < MAXTRY - 1; i++) {
        if (indovina[i] == parolaInput[k][pos] && cont[parolaInput[k][pos] - 97] > 0 && flag == 0) {
            textcolor (YELLOW);
            cont[parolaInput[k][pos] - 97] -= 1;
            flag = 1;
        }
    }

}


void stampaTabella (char *indovina, char parolaInput[][MAXTRY], int c, int *cont, int *tmp)
{
    int i = 0, j = 0, k = 0;

    printf("%c", 218);

    for (i = 0; i < 3; i++) {
        printf("%c", 196);
    }
    for (i = 0; i < MAXTRY - 2; i++) {
        printf("%c", 194);
        for (j = 0; j < 3; j++)
            printf("%c", 196);
        }

    printf("%c", 191);
    for (k = 0; k < MAXTRY; k++) {
        printf("\n");
        for (i = 0; i < 26; i++) {
            cont[i] = tmp[i];
        }

        for (j = 0; j < MAXTRY - 1; j++) {
            printf("%c", 179);

            /*in queste procedure fa i controlli per la colorazione delle parole*/
            checkLetterYellow (indovina, parolaInput, j, cont, k);
            checkLetterGreen (indovina[j], parolaInput[k][j]);

            printf(" %c ", parolaInput[k][j]);
            textcolor (WHITE);

            i++;
        }
        printf("%c\n", 179);

        if (k != 5) {
            printf("%c", 195);
            for (i = 0; i < 3; i++) {
                printf("%c", 196);
            }
            for (i = 0; i < MAXTRY - 2; i++) {
                printf("%c", 197);
                for (j = 0; j < 3; j++) {
                    printf("%c", 196);
                }
            }
            printf("%c", 180);
        }
    }


    printf("%c", 192);
    for (i = 0; i < 3; i++) {
        printf("%c", 196);
    }
    for (i = 0; i < MAXTRY - 2; i++) {
        printf("%c", 193);
        for (j = 0; j < 3; j++)
            printf("%c", 196);
    }
        printf("%c", 217);
}



