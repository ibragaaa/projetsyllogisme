#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "listQuant.h"

/*fonction pour les liste de quantificateurs*/
/*50 quantificateurs max par list*/
quantificateurs *initListQuant(bool u, bool a)
{
    int taille = 50;
    quantificateurs *list = malloc(sizeof(quantificateurs));
    list->l = malloc(taille * sizeof(char *));
    list->size = 0;
    list->U = u;
    list->A = a;
    return list;
}
void freeListQuant(quantificateurs *list)
{
    for (int i = 0; i < list->size; i++)
    {
        free(list->l[i]);
    }
    free(list->l);
    free(list);
}
void addListQuant(quantificateurs *list, char *quant)
{
    if (list->size + 1 <= 50)
    {
        list->l[list->size] = strdup(quant);
        list->size++;
    }
    else
    {
        printf("La taille de la liste est au maximum\n");
    }
}

void printListQuant(quantificateurs *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("- %d : \"%s\"\n", i, list->l[i]);
    }
    printf("\n");
}
void printListQuant2(quantificateurs *list)
{
    for (int i = 0; i < list->size; i++)
    {
        printf("- %d : \"%s\"", i, list->l[i]);
    }
    printf("\n");
}
