#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "syllogisme.h"

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

void askSylo(Syllogysme *s)
{
    printf("Bonjour \nNous allons commencer la saisie d'un Syllogisme !! \n");

    int ordre = askOrderSeizure();
    if (ordre == 1)
    {
        printf("Vous avez choisi la 1er methode de saisie \n");
        methode1(s);
    }
    else if (ordre == 2)
    {
        printf("Vous avez choisi la 2eme methode de saisie \n");
        methode2(s);
    }
    else if (ordre == 0)
    {
        printf("saisie ANNULE\n");
    }
}

Syllogysme initSyllo()
{
    Syllogysme s;
    s.U1 = true;
    s.U2 = true;
    s.Uc = true;
    s.A1 = true;
    s.A2 = true;
    s.Ac = true;
    s.S = true;
    s.P = true;
    s.figure = 0;
    strcpy(s.predicat, "");
    strcpy(s.moyenTerme, "");
    strcpy(s.sujet, "");
    return s;
}

void methode1(Syllogysme *s)
{
    printf("Etape (1 / 7) :\n");
    printf("1er quant\n");
    askQuantificateur(s, 1);
    printf("Etape (2 / 7) :\n");
    printf("2eme quant\n");
    askQuantificateur(s, 2);
    printf("Etape (3 / 7) :\n");
    printf("3eme quant\n");
    askQuantificateur(s, 3);
    printf("Etape (4 / 7) :\n");
    printf("sujet\n");
    scanfNom("sujet", s, 1);
    printf("Etape (5 / 7) :\n");
    printf("predicat\n");
    scanfNom("predicat", s, 2);
    printf("Etape (6 / 7) :\n");
    printf("moyen terme\n");
    scanfNom("moyen terme", s, 3);
    printf("Etape (7 / 7) :\n");
    printf("Type de la figure\n");
    scanfTypeFigure(s);
    printSyll(s);
}
void methode2(Syllogysme *s)
{
}

void printSyll(Syllogysme *s)
{
    printf("Affichage du Syllogisme :\n");
    if (s->figure == 1)
    {
        printf("Figure : %d\n%s %s %s , %s %s %s , %s %s %s\n", s->figure, s->quant1, s->moyenTerme, s->predicat, s->quant2, s->sujet, s->moyenTerme, s->quant3, s->sujet, s->predicat);
    }
    else if (s->figure == 2)
    {
        printf("Figure : %d\n%s %s %s , %s %s %s , %s %s %s\n", s->figure, s->quant1, s->predicat, s->moyenTerme, s->quant2, s->sujet, s->moyenTerme, s->quant3, s->sujet, s->predicat);
    }
    else if (s->figure == 3)
    {
        printf("Figure : %d\n%s %s %s , %s %s %s , %s %s %s\n", s->figure, s->quant1, s->moyenTerme, s->predicat, s->quant2, s->moyenTerme, s->sujet, s->quant3, s->sujet, s->predicat);
    }
    else if (s->figure == 4)
    {
        printf("Figure : %d\n%s %s %s , %s %s %s , %s %s %s\n", s->figure, s->quant1, s->predicat, s->moyenTerme, s->quant2, s->moyenTerme, s->sujet, s->quant3, s->sujet, s->predicat);
    }
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

void scanfNom(char *nom, Syllogysme *s, int val)
{
    printf("Donner le %s du syllogisme , Attention 50 caractere MAX sinon ERREUR\n", nom);
    char sujet[50];
    scanf("%s", &sujet);
    printf("le %s : %s\n", nom, sujet);
    if (val == 1)
    {
        strcpy(s->sujet, sujet);
    }
    else if (val == 2)
    {
        strcpy(s->predicat, sujet);
    }
    else if (val == 3)
    {
        strcpy(s->moyenTerme, sujet);
    }
}

void scanfTypeFigure(Syllogysme *s)
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
        printf("Vous avez choisi la figure %d\n", val);
        s->figure = val;
    }
    else if (res != 1)
    {
        printf("Erreur\n");
    }
    else
    {
        printf("La saisie n'est pas VALIDE\n");
        scanfTypeFigure(s);
    }
}

void askQuantificateur(Syllogysme *s, int valQuant)
{
    printf("Quel type de quantificateur : 1 existentielle , 2 universelle , 3 universelle negatif , 4 existentielle negatif ou 0 pour annule la saisie \n");
    printf("Veuillez entrer le nombre entier 1, 2, 3, 4 ou 0 pour annule la saisie\n");
    int val = -1;
    int res = scanf("%d", &val);
    char *chaine;
    bool a, b;
    if (res == 1)
    {
        if (val == 1)
        {
            printf("Liste quantifications existentielles\n");
            printList(list_quant_existentielles, size_quant_existentielles);
            chaine = scanfList(list_quant_existentielles, size_quant_existentielles);
            a = false;
            b = true;
            /*Syllogysme.u1 = true ;
            Syllogysme.a1 = true ;
            truc.quand1 = "ehfbezfbez" ; */
        }
        else if (val == 2)
        {
            printf("Liste quantifications universelles\n");
            printList(list_quant_universelles, size_quant_universelles);
            chaine = scanfList(list_quant_universelles, size_quant_universelles);
            a = true;
            b = true;
        }
        else if (val == 3)
        {
            printf("Liste quantifications universelles negative\n");
            printList(list_quant_universelles_negatif, size_quant_universelles_negatif);
            chaine = scanfList(list_quant_universelles_negatif, size_quant_universelles_negatif);
            a = true;
            b = false;
        }
        else if (val == 4)
        {
            printf("Liste quantifications existentielles negative\n");
            printList(list_quant_universelles_negatif, size_quant_existentielles_negatif);
            chaine = scanfList(list_quant_universelles_negatif, size_quant_existentielles_negatif);
            a = false;
            b = false;
        }
        else if (val == 0)
        {
            printf("saisie ANNULE\n");
        }
        else
        {
            printf("La saisie n'est pas VALIDE\n");
            askQuantificateur(s, valQuant);
        }
        if (val >= 1 && val <= 4)
        {
            if (valQuant == 1)
            {
                s->U1 = a;
                s->A1 = b;
                strcpy(s->quant1, chaine);
            }
            else if (valQuant == 2)
            {
                s->U2 = a;
                s->A2 = b;
                strcpy(s->quant2, chaine);
            }
            else if (valQuant == 3)
            {
                s->Uc = a;
                s->Ac = b;
                strcpy(s->quant3, chaine);
            }
        }
    }
    else
    {
        printf("Erreur");
    }
}

char *scanfList(char **list, int size)
{
    printf("Entre un chiffre entre O et %d\n", size - 1);
    int val;
    int res = scanf("%d", &val);
    if (res == 1 && val >= 0 && val < size)
    {
        printf("Vous avez choisi le quantificateur : %s \n", list[val]);
        return list[val];
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
