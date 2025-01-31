#include <stdio.h>
#include <time.h>
#include <stdlib.h>

float misurazioni(float *med_i, float *max_i, float *min_i) // Funzione per calcolare la massima media e minima
{
    float temp = 0; // Variabile per memorizzare la temperatura temporanea
    *med_i = 0; // Reset della media
    *max_i = -1; // Reset della massima
    *min_i = 30; // Reset della minima

    int i = 0;
    for (i = 0; i < 24; i++)
    {
        temp = (rand() / (float)RAND_MAX) * 30; // Genera temperatura casuale tra 0 e 29
        *med_i += temp;

        if (temp > *max_i)
        {
            *max_i = temp;
        }
        if (temp < *min_i)
        {
            *min_i = temp;
        }
    }

    *med_i = *med_i / 24; // Calcolo della media
}
void stampaTabella(float settimana[21]) // Funzione per stampare la tabella
{
    int i;
    printf(" ____________________________________\n");
    printf("|        |        |         |        |\n");
    printf("| Giorno | Media  | Massimo | Minimo |\n");
    printf("|________|________|_________|________|\n");

    for (i = 0; i < 21; i += 3)
    {
        printf("|   %d    | %.2f  | %.2f   | %.2f   |\n", (i / 3) + 1, settimana[i], settimana[i + 1], settimana[i + 2]);
    }
    printf("|________|________|_________|________|\n");
}

int main()
{
    srand(time(NULL)); // Funzione che rende differenti i numeri generati a ogni esecuzione

    float max_i = 0;
    float min_i = 0;
    float med_i = 0;
    int i = 0;
    float giorno[3];
    float settimana[21];

for (i = 0; i < 21; i += 3) // Ciclo per calcolare la temperatura dei 7 giorni
{
    float giorno[3];

    misurazioni(&med_i, &max_i, &min_i);
    giorno[0] = med_i;
    giorno[1] = max_i;
    giorno[2] = min_i;

    misurazioni(&med_i, &max_i, &min_i);
    giorno[0] = (giorno[0] + med_i) / 2;
    giorno[1] = (giorno[1] + max_i) / 2;
    giorno[2] = (giorno[2] + min_i) / 2;
    settimana[i] = giorno[0];
    settimana[i + 1] = giorno[1];
    settimana[i + 2] = giorno[2];
}
    stampaTabella(settimana);
    return 0;
}