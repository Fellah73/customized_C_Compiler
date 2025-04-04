#include <stdio.h>
#include <string.h>
#include <stdbool.h>

// Declaration de la TS
typedef struct
{
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    char Value[7];
    bool isConst;

} TypeTS;

TypeTS ts[100];

// init compteur
int CpTS = 0;

int recherche(char entite[])
{

    int i = 0;
    while (i < CpTS)
    {
        if (strcmp(entite, ts[i].NomEntite) == 0)
            return i;
        i++;
    }

    return -1;
}

// Fonction d'insertion des entités du programme dans la TS

void inserer(char entite[], char code[], char type[], bool isConst)
{
    if (recherche(entite) == -1)
    {
        strcpy(ts[CpTS].NomEntite, entite);
        strcpy(ts[CpTS].CodeEntite, code);
        strcpy(ts[CpTS].TypeEntite, type);
        ts[CpTS].isConst = false;

        CpTS++;
    }
}

void update(char entite[], char type[], char isConst[], char value[])
{

    int index = recherche(entite);
    if (index != -1)
    {
        strcpy(ts[index].TypeEntite, type);
        strcpy(ts[index].Value, value);
        ts[index].isConst = (strcmp(isConst, "true") == 0);
    }
}

// Fonction d'affichage de la TS
void afficher()
{

    int i = 0;

    printf("\n/***************Table des mots cles ******************/\n");
    printf("_________________________________________________\n");
    printf("\t| NomEntite |\n");
    printf("_________________________________________________\n");
    for (i = 0; i < CpTS; i++)
    {
        if (strcmp(ts[i].CodeEntite, "motCle") == 0)
        {
            printf("\t|%10s |\n", ts[i].NomEntite);
        }
    }
    printf("_________________________________________________\n");

    printf("\n/***************Table des separateurs ******************/\n");
    printf("_________________________________________________\n");
    printf("\t| NomEntite |\n");
    printf("_________________________________________________\n");
    for (i = 0; i < CpTS; i++)
    {
        if (strcmp(ts[i].CodeEntite, "separateur") == 0)
        {
            printf("\t|%10s |\n", ts[i].NomEntite);
        }
    }
    printf("_________________________________________________\n");

    printf("\n/***************Table des identifiants ******************/\n");
    printf("_________________________________________________\n");
    printf("\t| NomEntite | TypeEntite | Const  |  Value     |\n");
    printf("_________________________________________________\n");
    for (i = 0; i < CpTS; i++)
    {
        if (strcmp(ts[i].CodeEntite, "Idf") == 0)
        {
            printf("\t|%10s |%10s |%6s |%6s | \n", ts[i].NomEntite, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[i].Value);
        }
    }
    printf("_________________________________________________\n");

    printf("le nombre d'entites est : %d\n", CpTS);
}
