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
/*Fonction qui prend en param un Syllogisme , elle demande a l'utilisateur qu'elle methode utiliser pour saisir un syllogisme
- 0 pour le rien faire
- 1 pour utiliser la methode 1
- 2 pour utiliser la methode 2
*/
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
/*fonction fais parti de la fonction askSylo pour la demande de saisie d'un syllogisme*/
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
        return askOrderSeizure();
    }
}
/*fonction qui initialise un Syllogisme */
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
    strcpy(s.quant1, "");
    strcpy(s.quant2, "");
    strcpy(s.quant3, "");
    strcpy(s.sujet, "");
    strcpy(s.predicat, "");
    strcpy(s.moyenTerme, "");
    return s;
}
/* fonction de saisie pour la methode 1*/
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
    strcpy(s->sujet, scanfNom("sujet"));
    printf("Etape (5 / 7) :\n");
    printf("predicat\n");
    strcpy(s->predicat, scanfNom("predicat"));
    printf("Etape (6 / 7) :\n");
    printf("moyen terme\n");
    strcpy(s->moyenTerme, scanfNom("moyen terme"));
    printf("Etape (7 / 7) :\n");
    printf("Type de la figure\n");
    scanfTypeFigure(s);
    printSyll(s);
}
/* fonction de saisie pour la methode 2*/
void methode2(Syllogysme *s)
{
    printf("Etape (1 / 9) :\n");
    printf("1er quant\n");
    askQuantificateur(s, 1);
    printf("Etape (2 / 9) :\n");
    char sujet1[50];
    strcpy(sujet1, scanfNom("sujet"));
    printf("Etape (3 / 9) :\n");
    char predicat1[50];
    strcpy(predicat1, scanfNom("predicat"));
    printf("Etape (4 / 9) :\n");
    printf("2eme quant\n");
    askQuantificateur(s, 2);
    printf("Etape (5 / 9) :\n");
    char sujet2[50];

    strcpy(sujet2, demande1(sujet1, predicat1, s));
    if (strcmp(sujet2, "") == 0)
    {
        printf("ERREUR");
    }
    else
    {
        if (strcmp(sujet2, sujet1) == 0)
        {
            strcpy(s->moyenTerme, sujet1);
            strcpy(s->predicat, predicat1);
        }
        else if (strcmp(sujet2, predicat1) == 0)
        {
            strcpy(s->predicat, sujet1);
            strcpy(s->moyenTerme, predicat1);
        }
        else
        {
            strcpy(s->sujet, sujet2);
        }
    }
    printf("Etape (6 / 9) :\n");
    if (strcmp(s->sujet, "") == 0)
    {
        strcpy(s->sujet, scanfNom("predicat de la 2eme proposition"));
    }
    else
    {
        printf("Il n'y a pas d'etape 6 dans se cas\n");
    }

    printf("Etape (7 / 9) :\n");
    printf("quantificateur de la conclusion\n");
    askQuantificateur(s, 3);
    printf("Etape (8 / 9) :\n");
    demande2(s);
    printf("Etape (9 / 9) :\n");

    printSyll(s);
}
/*focntion qui demande a l'utilisateur si le sujet de la deuxime
proposition est le sujet ou le predicat de la premiere
si oui pas de saisie de */
char *demande1(char *s1, char *s2, Syllogysme *s)
{
    printf("le sujet de la deuxieme premisse est : \"%s\" , \"%s\" ou autre :\n", s1, s2);
    printf("- 0 pour annule la saisie\n");
    printf("- 1 pour %s\n", s1);
    printf("- 2 pour %s\n", s2);
    printf("- 3 pour la saisie du sujet\n");
    int a;
    int ret = scanf("%d", &a);
    char *res;
    strcpy(res, "");
    if (ret != 1)
    {
        printf("Erreur\n");
    }
    else
    {
        if (a == 0)
        {
            printf("FIN DE LA SAISIE\n");
        }
        else if (a == 1)
        {
            s->figure = 3;
            s->S = false;
            s->P = true;
            strcpy(res, s1);
        }
        else if (a == 2)
        {
            s->figure = 4;
            s->S = false;
            s->P = false;
            strcpy(res, s2);
        }
        else if (a == 3)
        {
            printf("fais\n");
            strcpy(res, scanfNom("sujet"));
        }
        else
        {
            printf("La saisie n'est pas VALIDE\n");
            demande1(s1, s2, s);
        }
    }
    return res;
}

void demande2(Syllogysme *s)
{
    printf("le sujet de la conclusion est le sujet de la 2eme premisse ou le predicat de la 2eme premisse \n");
    printf("- 0 pour annule la saisie\n");
    printf("- 1 le sujet est sujet dans la 2eme premisse\n");
    printf("- 2 le sujet est le predicat de la 2eme premisse\n");
    int a;
    int ret = scanf("%d", &a);
    if (ret != 1)
    {
        printf("Erreur\n");
    }
    else
    {
        if (a == 1)
        {
        }
        else if (a == 2)
        {
        }
        else
        {
            printf("La saisie n'est pas VALIDE\n");
            demande2(s);
        }
    }
}

/*Fonction qui affiche un syllogisme en fonction du type de figure */
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
    printf("U1 : %d ,U2 : %d ,Uc : %d ,A1 : %d ,A2 : %d ,Ac : %d ,S : %d ,P : %d\n", s->U1, s->U2, s->Uc, s->A1, s->A2, s->Ac, s->S, s->P);
}

/*fonction qui prend en param le nom : soit le sujet , soit le predicat , soit le moyen terme ( juste pour l'affichage)
et un entier val avec trois valeur possible 1 , 2 ou 3 respectivement sujet , predicat , moyen terme */
char *scanfNom(char *nom)
{
    printf("Donner le %s du syllogisme , Attention 50 caractere MAX sinon ERREUR\n", nom);
    printf("!!!!!!!!!!!! <  #  > pour arrete la saisie !!!!!!!!!!!!!!!\n");
    char *sujet;
    strcpy(sujet, "");
    bool sorti = true;
    while (sorti)
    {
        char compare[50];
        scanf("%s", &compare);
        if (strcmp(compare, "#") == 0)
        {
            sorti = false;
        }
        else
        {
            strcat(sujet, compare);
            strcat(sujet, " ");
        }
    }
    printf("le %s : %s\n", nom, sujet);
    return sujet;
}
/*fonction qui fais la demande du type de figure choisi
- 0 pour annule la saisie
- 1,2,3,4 pour la figure choisie*/
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
        if (val == 1)
        {
            s->P = true;
            s->S = true;
        }
        else if (val == 2)
        {
            s->P = false;
            s->S = true;
        }
        else if (val == 3)
        {
            s->P = true;
            s->S = false;
        }
        else if (val == 4)
        {
            s->P = false;
            s->S = false;
        }
        else if (val == 0)
        {
            printf("Saisie ANNULE");
        }
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
/*fonction qui demande a l'utilisateur quel type de quntificateur il choisi
- 0 pour annule la saisie
- 1 quantificateur existencielles
- 2 quantificateur universelles
- 3 quantificateur universelles negatif
- 4 quantificateur existencielles negatif
*/
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
/*fonction qui revoie une chaine de carractere choisi en fonction d'un liste donner et de sa taille en demandant un chiffre valide a l'utilisateur  */
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
        return scanfList(list, size);
    }
}
/*fonction qui affiche une liste donner en param avec la taille de la liste */
void printList(char **list, int size)
{
    for (int i = 0; i < size; i++)
    {
        printf("%3d :  %s\n", i, list[i]);
    }
}
