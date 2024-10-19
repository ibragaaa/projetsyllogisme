#ifndef SYLLOGISME_H
#define SYLLOGISME_H

#include <stdbool.h>

typedef struct
{
    bool U1, U2, Uc, A1, A2, Ac, S, P;
    char quant1[50], quant2[50], quant3[50], sujet[50], predicat[50], moyenTerme[50];
    int figure;
} Syllogysme;

void askSylo(Syllogysme *s);
Syllogysme initSyllo();
int askOrderSeizure();
void askQuantificateur(Syllogysme *s, int valQuant);
void printList(char **list, int size);
void methode1(Syllogysme *s);
void methode2(Syllogysme *s);
char *scanfList(char **list, int size);
char *scanfNom(char *nom);
void scanfTypeFigure(Syllogysme *s);
void printSyll(Syllogysme *s);

char *demande1(char *s1, char *s2, Syllogysme *s);
void demande1_bis(char *s1, char *s2, Syllogysme *s);
void demande2(Syllogysme *s);

#endif
