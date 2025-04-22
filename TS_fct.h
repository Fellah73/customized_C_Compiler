#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct TypeTS
{
    char NomEntite[20];
    char CodeEntite[20];
    char TypeEntite[20];
    char Value[7];
    int Length;
    bool isConst;
    struct TypeTS *next;
} TypeTS;

TypeTS *head = NULL;
int CpTS = 0;

int recherche(char entite[])
{
    TypeTS *current = head;
    int i = 0;

    while (current != NULL)
    {
        if (strcmp(entite, current->NomEntite) == 0)
            return i;

        current = current->next;
        i++;
    }

    return -1;
}

TypeTS *getNode(int index)
{
    if (index < 0 || index >= CpTS)
        return NULL;

    TypeTS *current = head;
    int i = 0;

    while (current != NULL && i < index)
    {
        current = current->next;
        i++;
    }

    return current;
}

int inserer(char entite[], char code[], char type[], char isConst[])
{
    if (entite[0] == '?' && entite[1] == '?' && entite[2] == '?')
    {
        return 0;
    }

    int index = recherche(entite);
    if (index == -1)
    {
        TypeTS *newNode = (TypeTS *)malloc(sizeof(TypeTS));
        if (newNode == NULL)
        {
            printf("Memory allocation failed\n");
            return -2;
        }

        strcpy(newNode->NomEntite, entite);
        strcpy(newNode->CodeEntite, code);
        strcpy(newNode->TypeEntite, type);
        strcpy(newNode->Value, "null");
        newNode->isConst = (strcmp(isConst, "true") == 0) ? true : false;
        newNode->Length = 0;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        else
        {
            TypeTS *current = head;
            while (current->next != NULL)
            {
                current = current->next;
            }
            current->next = newNode;
        }

        CpTS++;
        return 1;
    }
    return -1;
}

int update(char entite[], char type[], char isConst[], char value[], int length)
{
    int index = recherche(entite);

    if (length <= 0)
    {
        TypeTS *node = getNode(index);
        if (node != NULL)
        {
            node->Length = 0;
        }
        return -2;
    }

    if (index == -1)
    {
        return -1;
    }

    if (value[0] == '(')
    {
        printf("la valeur ne doit pas etre signe\n");
    }

    if (index != -1)
    {
        TypeTS *node = getNode(index);
        if (node != NULL)
        {
            strcpy(node->TypeEntite, type);
            strcpy(node->Value, value);
            node->isConst = (strcmp(isConst, "true") == 0);
            node->Length = length;
        }
    }
    return index + 1;
}

void afficher()
{
    TypeTS *current = head;

    printf("\n/***************Table des mots cles ******************/\n");
    printf("_________________________________________________\n");
    printf("\t| NomEntite |\n");
    printf("_________________________________________________\n");
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->CodeEntite, "motCle") == 0)
        {
            printf("\t|%10s |\n", current->NomEntite);
        }
        current = current->next;
    }
    printf("_________________________________________________\n");

    printf("\n/***************Table des separateurs ******************/\n");
    printf("_________________________________________________\n");
    printf("\t| NomEntite |\n");
    printf("_________________________________________________\n");
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->CodeEntite, "separateur") == 0)
        {
            printf("\t|%10s |\n", current->NomEntite);
        }
        current = current->next;
    }
    printf("_________________________________________________\n");

    printf("\n/***************Table des identifiants ******************/\n");
    printf("________________________________________________________________________\n");
    printf("\t| NomEntite | TypeEntite | Const      |  Value     |   Length   |\n");
    printf("_________________________________________________________________________\n");
    current = head;
    while (current != NULL)
    {
        if (strcmp(current->CodeEntite, "Idf") == 0)
        {
            printf("\t|%10s |%10s  |%10s  |%10s  |%d \n",
                   current->NomEntite,
                   current->TypeEntite,
                   current->isConst ? "true" : "false",
                   current->Value,
                   current->Length);
        }
        current = current->next;
    }
    printf("________________________________________________________________________\n");

    printf("le nombre d'entites est : %d\n", CpTS);
}

int isConst(char entite[])
{
    int index = recherche(entite);
    if (index == -1)
    {
        return -1;
    }

    TypeTS *node = getNode(index);
    if (node != NULL)
    {
        return node->isConst ? 1 : 0;
    }
    return -1;
}

void freeSymbolTable()
{
    TypeTS *current = head;
    TypeTS *next;

    while (current != NULL)
    {
        next = current->next;
        free(current);
        current = next;
    }

    head = NULL;
    CpTS = 0;
}
