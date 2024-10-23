#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "saisi_syllo.h"

/*fonction qui initialise un syllogisme */
syllogisme *initSyllo()
{
    syllogisme *s = malloc(sizeof(syllogisme));
    int taille = 50;
    s->quant1 = malloc(taille * sizeof(char));
    s->quant2 = malloc(taille * sizeof(char));
    s->quant3 = malloc(taille * sizeof(char));
    s->sujet = malloc(taille * sizeof(char));
    s->predicat = malloc(taille * sizeof(char));
    s->moyenTerme = malloc(taille * sizeof(char));
    /*
    s->U1 = true;
    s->U2 = true;
    s->Uc = true;
    s->A1 = true;
    s->A2 = true;
    s->Ac = true;
    s->S = true;
    s->P = true;
    */
    s->figure = 0;
    s->quant1[0] = '\0';
    s->quant2[0] = '\0';
    s->quant3[0] = '\0';
    s->sujet[0] = '\0';
    s->predicat[0] = '\0';
    s->moyenTerme[0] = '\0';
    return s;
}
/*fonction qui free un syllogisme */
void freeSyllo(syllogisme *s)
{
    free(s->quant1);
    free(s->quant2);
    free(s->quant3);
    free(s->sujet);
    free(s->predicat);
    free(s->moyenTerme);
    free(s);
}

/*fonction qui affiche un syllogisme*/

void printSyllo(syllogisme *s)
{
    printf("Affichage du Syllogisme :\n");
    if (s->figure == 0)
    {
        printf("Le syllogisme n'est pas construit\n");
    }
    else
    {
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
        printf("Le sujet est < %s > , le predicat est < %s > , le moyen terme est < %s > \n", s->sujet, s->predicat, s->moyenTerme);
    }
}

/*fonction Saisie d'un Syllogisme*/

/*fonction qui demande un entier a l'utilisateur de 0 a un entier positif max,
si une chaine de carac ou autre qu'un nb est rentré on vide le buffer  */
int askInt(int max)
{
    int a;
    int ret;
    do
    {
        printf("Entre le nombre entre 0 et %d\n", max);
        ret = scanf("%d", &a);
        if (ret != 1)
        {
            int c = 0;
            while (c != '\n')
            {
                c = getchar();
            }
            printf("Il faut rentrer un nombre\n");
        }
    } while (!(0 <= a && a <= max) || ret != 1);
    return a;
}

/*fonction qui demande une chaine de caractere a l'utilisateur , elle doit finir par <!> pour finir la saisie*/
char *askString()
{
    int taille = 50;
    char *res = malloc(taille * sizeof(char));
    res[0] = '\0';
    bool s = true;
    int size = 0;
    while (s)
    {
        char tmp[100];
        scanf("%s", &tmp);
        if (strcmp(tmp, "!") == 0)
        {
            s = false;
        }
        else
        {
            size += strlen(tmp) + 1;
            if (size > taille)
            {
                taille *= 2;
                res = realloc(res, taille * sizeof(char));
            }
            strcat(res, tmp);
            strcat(res, " ");
        }
    }
    int size_res = strlen(res);
    if (size_res > 0 && res[size_res - 1] == ' ')
    {
        res[size_res - 1] = '\0';
    }
    return res;
}

/*fonction qui ajoute ou non des chaines de caractere dans les 4 liste donnes */
void changeList(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d)
{
    printf("Avant de commencer voici la liste des Quantificateurs possible\n");
    printf("************  Universelles  ************\n");
    printListQuant2(a);
    printf("************  Universelles Negative  ************\n");
    printListQuant2(b);
    printf("************  existentielles  ************\n");
    printListQuant2(c);
    printf("************  existentielles Negative  ************\n");
    printListQuant2(d);
    bool s = true;
    while (s)
    {
        printf("Voulez-vous ajouter des quantificateurs ? \n");
        printf("si oui tapez <1> , sinon tapez <0>\n");
        int v = askInt(1);
        if (v == 1)
        {
            printf("A quel liste voulez-vous ajouter un quantificateur? \n");
            printf("<0> pour annule la saisie\n");
            printf("<1> pour Universelles\n");
            printf("<2> pour Universelles Negatives\n");
            printf("<3> pour Existentielles\n");
            printf("<4> pour Existentielles Negatives\n");
            int i = askInt(4);
            if (i >= 0 && i <= 4)
            {
                if (i == 0)
                {
                    printf("Vous-avez annule la saisie !!!!!!!!\n");
                    exit(0);
                }
                else
                {
                    printf("tapez le quantificateur (<!> pour stoper la saisie): ");
                    char *my = askString();
                    printf("Vous avez saisie le Quantificateur < %s > ", my);

                    if (i == 1)
                    {
                        addListQuant(a, my);
                        printf("dans Universelles\n");
                    }
                    else if (i == 2)
                    {
                        addListQuant(b, my);
                        printf("dans Universelles Negatives\n");
                    }
                    else if (i == 3)
                    {
                        addListQuant(c, my);
                        printf("dans Existentielles\n");
                    }
                    else
                    {
                        addListQuant(d, my);
                        printf("dans Existentielles Negatives\n");
                    }
                    free(my);
                }
            }
            else
            {
                exit(EXIT_FAILURE);
            }
        }
        else
        {
            s = false;
        }
    }
}

void saisie(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s)
{
    printf("***** Debut de la saisie du syllogisme *****\n");
    printf("Choisisez le mode de saisie : \n");
    printf("<1> mode 1 \n");
    printf("<2> mode 2 \n");
    int i = askInt(2);
    if (i == 1)
    {
        mode1(a, b, c, d, s);
    }
    else if (i == 2)
    {
        mode2(a, b, c, d, s);
    }
    else if (i == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

/* fonction de saisie pour la methode 1*/
void mode1(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s)
{
    printf("Vous-avez choisi le mode 1\n");
    printf("Etape (1 / 7) :\n");
    printf("Entre le premier quantificateur du syllogisme\n");
    askQuant(a, b, c, d, s, 1);
    printf("Etape (2 / 7) :\n");
    printf("Entre le deuxieme quantificateur du syllogisme\n");
    askQuant(a, b, c, d, s, 2);
    printf("Etape (3 / 7) :\n");
    printf("Entre le troixieme quantificateur du syllogisme\n");
    askQuant(a, b, c, d, s, 3);
    printf("Etape (4 / 7) :\n");
    printf("Entre le sujet du syllogisme\n");
    char *sujet = askString();
    s->sujet = realloc(s->sujet, (strlen(sujet) + 1) * sizeof(char));
    strcpy(s->sujet, sujet);
    free(sujet);
    printf("Etape (5 / 7) :\n");
    printf("Entre le predicat du syllogisme\n");
    char *predicat = askString();
    s->predicat = realloc(s->predicat, (strlen(predicat) + 1) * sizeof(char));
    strcpy(s->predicat, predicat);
    free(predicat);
    printf("Etape (6 / 7) :\n");
    printf("Entre le moyen terme du syllogisme\n");
    char *moyenTerme = askString();
    s->moyenTerme = realloc(s->moyenTerme, (strlen(moyenTerme) + 1) * sizeof(char));
    strcpy(s->moyenTerme, moyenTerme);
    free(moyenTerme);
    printf("Etape (7 / 7) :\n");
    scanfTypeFigure(s);
    printSyllo(s);
}

void mode2(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s)
{
    printf("Vous-avez choisi le mode 2\n");
    printf("Etape (1 / 9) :\n");
    printf("Entre le quantificateur de la premiere premisse du syllogisme\n");
    askQuant(a, b, c, d, s, 1);
    printf("Etape (2 / 9) :\n");
    printf("Entre le sujet de la premiere premisse du syllogisme\n");
    char *sujet = askString();
    printf("Etape (3 / 9) :\n");
    printf("Entre le predicat de la premiere premisse du syllogisme\n");
    char *predicat = askString();
    printf("Etape (4 / 9) :\n");
    printf("Entre le quantificateur de la deuxieme premisse du syllogisme\n");
    askQuant(a, b, c, d, s, 2);
    printf("Etape (5 / 9) :\n");
    bool booll = mode2_1(s);
    printf("Etape (6 / 9) :\n");
    if (booll)
    {
        printf("Entre le predicat de la deuxieme premisse du syllogisme\n");
        char *predicat2 = askString();
        s->sujet = realloc(s->sujet, (strlen(predicat2) + 1) * sizeof(char));
        strcpy(s->sujet, predicat2);
        free(predicat2);
    }
    else
    {
        mode2_2(s);
    }
    printf("Etape (7 / 9) :\n");
    printf("Entre le quantificateur de la conclusion du syllogisme\n");
    askQuant(a, b, c, d, s, 3);
    printf("Etape (8 / 9) :\n");
    mode2_3(s);
    printf("Etape (9 / 9) :\n");
    printf("Le sujet de la conclusion est < %s >\n", s->sujet);
    printf("Par deduction le predicat de la conclusion est < %s >\n", s->predicat);

    detSyllo(sujet, predicat, s);

    printSyllo(s);

    free(sujet);
    free(predicat);
}

bool mode2_1(syllogisme *s)
{
    printf("Le sujet de la deuxieme premisse est :\n");
    printf("<0> pour annule la saisie\n");
    printf("<1> le sujet de la premiere premisse\n");
    printf("<2> le predicat de la premiere premisse\n");
    printf("<3> aucun des deux \n");
    int i = askInt(3);
    bool sorti = true;
    if (i == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else
    {
        if (i == 1)
        {
            s->P = true;
        }
        else if (i == 2)
        {
            s->P = false;
        }
        else if (i == 3)
        {
            printf("Entre le sujet de la deuxieme premisse du syllogisme\n");
            char *chaine = askString();
            s->sujet = realloc(s->sujet, (strlen(chaine) + 1) * sizeof(char));
            strcpy(s->sujet, chaine);
            free(chaine);
            sorti = false;
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
    return sorti;
}

void mode2_2(syllogisme *s)
{
    printf("Le predicat de la deuxieme premisse du syllogisme est :\n");
    printf("<0> pour annule la saisie\n");
    printf("<1> le sujet de la premiere premisse\n");
    printf("<2> le predicat de la premiere premisse\n");
    int i = askInt(2);
    if (i == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else
    {
        if (i == 1)
        {
            s->P = true;
        }
        else if (i == 2)
        {
            s->P = false;
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
}

void mode2_3(syllogisme *s)
{
    printf("Le sujet de la conclusion du syllogisme est :\n");
    printf("<0> pour annule la saisie\n");
    printf("<1> le sujet de la deuxieme premisse\n");
    printf("<2> le predicat de la deuxieme premisse\n");
    int i = askInt(2);
    if (i == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else
    {
        if (i == 1)
        {
            s->S = true;
        }
        else if (i == 2)
        {
            s->S = false;
        }
        else
        {
            exit(EXIT_FAILURE);
        }
    }
}
/*fonction qui determine la figure d'un syllogisme avec les 2 bool s.S et s.P */
void detSyllo(char *s1, char *p1, syllogisme *s)
{
    if (s->P)
    {
        if (s->S)
        {
            s->figure = 1;
        }
        else
        {
            s->figure = 3;
        }
        s->moyenTerme = realloc(s->moyenTerme, (strlen(s1) + 1) * sizeof(char));
        strcpy(s->moyenTerme, s1);
        s->predicat = realloc(s->predicat, (strlen(p1) + 1) * sizeof(char));
        strcpy(s->predicat, p1);
    }
    else
    {
        if (s->S)
        {
            s->figure = 2;
        }
        else
        {
            s->figure = 4;
        }
        s->predicat = realloc(s->predicat, (strlen(s1) + 1) * sizeof(char));
        strcpy(s->predicat, s1);
        s->moyenTerme = realloc(s->moyenTerme, (strlen(p1) + 1) * sizeof(char));
        strcpy(s->moyenTerme, p1);
    }
}

/*fonction qui demande a l'utilisateur quel type de quntificateur il choisi
- 0 pour annule la saisie
- 1 quantificateur universelles
- 2 quantificateur universelles negatif
- 3 quantificateur existentielles
- 4 quantificateur existentielles negatif
*/
void askQuant(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s, int num)
{
    printf("Quel type de quantificateur :\n");
    printf("<0> ANNULE LA SAISIE\n");
    printf("<1> universelle \n");
    printf("<2> universelle negatif \n");
    printf("<3> existentielle \n");
    printf("<4> existentielle negatif \n");
    int i = askInt(4);
    char *chaine;
    bool U, A;
    if (i == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else if (i == 1)
    {
        printf("Liste quantifications universelles\n");
        printListQuant(a);
        chaine = getListQuant(a);
        U = a->U;
        A = a->A;
    }
    else if (i == 2)
    {
        printf("Liste quantifications universelles negative\n");
        printListQuant(b);
        chaine = getListQuant(b);
        U = b->U;
        A = b->A;
    }
    else if (i == 3)
    {
        printf("Liste quantifications existentielles\n");
        printListQuant(c);
        chaine = getListQuant(c);
        U = c->U;
        A = c->A;
    }
    else if (i == 4)
    {
        printf("Liste quantifications existentielles negative\n");
        printListQuant(d);
        chaine = getListQuant(d);
        U = d->U;
        A = d->A;
    }
    else
    {
        exit(EXIT_FAILURE);
    }
    if (num == 1)
    {
        s->U1 = U;
        s->A1 = A;
        strcpy(s->quant1, chaine);
    }
    else if (num == 2)
    {
        s->U2 = U;
        s->A2 = A;
        strcpy(s->quant2, chaine);
    }
    else if (num == 3)
    {
        s->Uc = U;
        s->Ac = A;
        strcpy(s->quant3, chaine);
    }
    else
    {
        exit(EXIT_FAILURE);
    }
}

char *getListQuant(quantificateurs *list)
{
    int i = askInt(list->size - 1);
    printf("Vous avez choisi le quantificateur : %s \n", list->l[i]);
    return list->l[i];
}

/*fonction qui fais la demande du type de figure choisi
- 0 pour annule la saisie
- 1,2,3,4 pour la figure choisie*/
void scanfTypeFigure(syllogisme *s)
{
    printf(" ------------       ------------       ------------       ------------ \n");
    printf("|  Figure 1  |     |  Figure 2  |     |  Figure 3  |     |  Figure 4  |\n");
    printf("| M   ->   P |     | P   ->   M |     | M   ->   P |     | P   ->   M |\n");
    printf("| S   ->   M |     | S   ->   M |     | M   ->   S |     | M   ->   S |\n");
    printf("| S   ->   P |     | S   ->   P |     | S   ->   P |     | S   ->   P |\n");
    printf(" ------------       ------------       ------------       ------------ \n");

    printf("Quel est le numero de la figure du syllogisme:\n");
    printf("<0> pour annule la saisie\n");
    printf("<1> figure\n");
    printf("<2> figure\n");
    printf("<3> figure\n");
    printf("<4> figure\n");
    int val = askInt(4);
    if (val == 0)
    {
        printf("Vous-avez annule la saisie !!!!!!!!\n");
        exit(0);
    }
    else
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
        else
        {
            exit(EXIT_FAILURE);
        }
    }
}
