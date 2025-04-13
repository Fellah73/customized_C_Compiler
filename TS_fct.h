#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef struct
{
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    char Value[7];
    int Length;
    bool isConst;

} TypeTS;

TypeTS ts[100];

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

int inserer(char entite[], char code[], char type[], char isConst[])
{
    if (entite[0] == '?' && entite[1] == '?' && entite[2] == '?')
    {
        return 0;
    }
    int index = recherche(entite);
    if (index == -1)
    {
        strcpy(ts[CpTS].NomEntite, entite);
        strcpy(ts[CpTS].CodeEntite, code);
        strcpy(ts[CpTS].TypeEntite, type);
        strcpy(ts[CpTS].Value, "null");
        ts[CpTS].isConst = (strcmp(isConst, "true") == 0) ? true : false;
        ts[CpTS].Length = 0;
        CpTS++;
        return 1;
    }
    return -1;
}

int update(char entite[], char type[], char isConst[], char value[], int length)
{

    int index = recherche(entite);

    // the array length must be greater than 0
    if (length <= 0)
    {
        ts[index].Length = 0;
        return -2;
    }

    // si l'entite n'existe pas
    if (index == -1)
    {
        return -1;
    }

    // si la vlauer est signée
    if (value[0] == '(')
    {
        printf("la valeur ne doit pas etre signe\n");
    }

    // si l'entite existe deja
    if (index != -1)
    {
        strcpy(ts[index].TypeEntite, type);
        strcpy(ts[index].Value, value);
        ts[index].isConst = (strcmp(isConst, "true") == 0);
        ts[index].Length = length;
    }
    return index + 1;
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
    printf("___________________________________________________________________\n");
    printf("\t| NomEntite | TypeEntite | Const      |  Value     |   Length   |\n");
    printf("___________________________________________________________________\n");
    for (i = 0; i < CpTS; i++)
    {
        if (strcmp(ts[i].CodeEntite, "Idf") == 0)
        {
            printf("\t|%10s |%10s  |%10s  |%10s  |%d \n", ts[i].NomEntite, ts[i].TypeEntite, ts[i].isConst ? "true" : "false", ts[i].Value, ts[i].Length);
        }
    }
    printf("_________________________________________________\n");

    printf("le nombre d'entites est : %d\n", CpTS);
}

int isConst(char entite[])
{
    int index = recherche(entite);
    if (index == -1)
    {
        return -1;
    }
    return ts[index].isConst ? 1 : 0;
}
