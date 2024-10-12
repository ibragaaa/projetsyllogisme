#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "syllogisme.h"

typedef struct
{
    bool U1, U2, Uc, A1, A2, Ac, S, P;
} Syllogysme;

typedef struct
{
    char *quant1, quant2, quant3, sujet, predicat, moyenTerme
} truc;

int size_quant_universelles = 12;
char *list_quant_universelles[] = {
    "Tout",
    "Tous",
    "Chaque",
    "Chacun(e)",
    "N'importe quel(le)",
    "Quiconque",
    "Peu importe qui",
    "Peu importe quoi",
    "Qui que ce soit",
    "Quel(le) que soit",
    "Quoi que",
    "Ou que"};

int size_quant_universelles_negatif = 3;
char *list_quant_universelles_negatif[] = {
    "Personne",
    "Rien",
    "Aucun"};

int size_quant_existentielles = 10;
char *list_quant_existentielles[] = {
    "Quelqu'un",
    "Quelque chose",
    "Certains / Certaines",
    "Un(e)",
    "Il existe",
    "Il y a",
    "Un(e) certain(e)",
    "Au moins un(e)",
    "Quel que",
    "Parfois"};

int size_quant_existentielles_negatif = 2;
char *list_quant_existentielles_negatif[] = {
    "Pas tout le monde",
    "Pas toujours"};

void askSylo()
{
    printf("Bonjour \nNous allons commencer la saisie d'un Syllogisme !! \n");

    int ordre = askOrderSeizure();
    if (ordre == 1)
    {
        printf("Vous avez choisi la 1er methode de saisie \n");
        methode1();
    }
    else if (ordre == 2)
    {
        printf("Vous avez choisi la 2eme methode de saisie \n");
        methode2();
    }
    else if (ordre == 0)
    {
        printf("saisie ANNULE\n");
    }
}

void methode1()
{
    printf("Etape (1 / 7) :\n");
    printf("1er quant\n");
    askQuantificateur();
    printf("Etape (2 / 7) :\n");
    printf("2eme quant\n");
    askQuantificateur();
    printf("Etape (3 / 7) :\n");
    printf("3eme quant\n");
    askQuantificateur();
    printf("Etape (4 / 7) :\n");
    printf("sujet\n");
    scanfNom("sujet");
    printf("Etape (5 / 7) :\n");
    printf("predicat\n");
    scanfNom("predicat");
    printf("Etape (6 / 7) :\n");
    printf("moyen terme\n");
    scanfNom("moyen terme");
    printf("Etape (7 / 7) :\n");
    printf("Type de la figure\n");
    scanfTypeFigure();
}
void methode2()
{
}

int askOrderSeizure()
{
    printf("Quel est l'ordre de saisie du syllogisme choisi , Ordre : 1 avec 7 demandes ou 2 avec 9 demandes mais dans l'ordre de lecture du syllogisme\n");
    printf("Veuillez entrer le nombre entier 1 ou 2 ou 0 pour annule la saisie\n");
    int ordre = -1;
    int res = scanf("%d", &ordre);
    if (res == 1 && (ordre == 1 || ordre == 2 || ordre == 0))
    {
        return ordre;
    }
    else if (res != 1)
    {
        printf("Erreur  ");
    }
    else
    {
        printf("La saisie n'est pas VALIDE\n");
        askOrderSeizure();
    }
}

void scanfNom(char *nom)
{
    printf("Donner le %s du syllogisme , Attention 100 caractere MAX sinon ERREUR\n", nom);
    char sujet[100];
    scanf("%s", &sujet);
    printf("le %s : %s\n", nom, sujet);
}

void scanfTypeFigure()
{
    printf(" ------------       ------------       ------------       ------------ \n");
    printf("|  Figure 1  |     |  Figure 2  |     |  Figure 3  |     |  Figure 4  |\n");
    printf("| M   ->   P |     | P   ->   M |     | M   ->   P |     | P   ->   M |\n");
    printf("| S   ->   M |     | S   ->   M |     | M   ->   S |     | M   ->   S |\n");
    printf("| S   ->   P |     | S   ->   P |     | S   ->   P |     | S   ->   P |\n");
    printf(" ------------       ------------       ------------       ------------ \n");

    printf("Quel est le numero de la figure du syllogisme : 1 , 2 , 3 ou 4 \n");
    printf("0 pour annule la saisie\n");
    int val;
    int res = scanf("%d", &val);
    if (res == 1 && val >= 0 && val <= 4)
    {
        printf("Vous avez choisi la figure %d", val);
    }
    else if (res != 1)
    {
        printf("Erreur");
    }
    else
    {
        printf("La saisie n'est pas VALIDE\n");
        scanfTypeFigure();
    }
}

void askQuantificateur()
{
    printf("Quel type de quantificateur : 1 existentielle , 2 universelle , 3 universelle negatif , 4 existentielle negatif ou 0 pour annule la saisie \n");
    printf("Veuillez entrer le nombre entier 1, 2, 3, 4 ou 0 pour annule la saisie\n");
    int val = -1;
    int res = scanf("%d", &val);
    if (res == 1)
    {
        if (val == 1)
        {
            printf("Liste quantifications existentielles\n");
            printList(list_quant_existentielles, size_quant_existentielles);
            scanfList(list_quant_existentielles, size_quant_existentielles);
            /*Syllogysme.u1 = true ;
            Syllogysme.a1 = true ;
            truc.quand1 = "ehfbezfbez" ; */
        }
        else if (val == 2)
        {
            printf("Liste quantifications universelles\n");
            printList(list_quant_universelles, size_quant_universelles);
            scanfList(list_quant_universelles, size_quant_universelles);
        }
        else if (val == 3)
        {
            printf("Liste quantifications universelles negative\n");
            printList(list_quant_universelles_negatif, size_quant_universelles_negatif);
            scanfList(list_quant_universelles_negatif, size_quant_universelles_negatif);
        }
        else if (val == 4)
        {
            printf("Liste quantifications existentielles negative\n");
            printList(list_quant_universelles_negatif, size_quant_existentielles_negatif);
            scanfList(list_quant_universelles_negatif, size_quant_existentielles_negatif);
        }
        else if (val == 0)
        {
            printf("saisie ANNULE\n");
        }
        else
        {
            printf("La saisie n'est pas VALIDE\n");
            askQuantificateur();
        }
    }
    else
    {
        printf("Erreur");
    }
}

void scanfList(char **list, int size)
{
    printf("Entre un chiffre entre O et %d\n", size - 1);
    int val;
    int res = scanf("%d", &val);
    if (res == 1 && val >= 0 && val < size)
    {
        printf("Vous avez choisi le quantificateur : %s \n", list[val]);
    }
    else if (res != 1)
    {
        printf("Erreur");
    }
    else
    {
        printf("La saisie n'est pas VALIDE\n");
        scanfList(list, size);
    }
}

void printList(char **list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d :  %s\n", i, list[i]);
    }
}
