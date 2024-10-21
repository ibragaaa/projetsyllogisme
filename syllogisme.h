#ifndef SYLLOGISME_H
#define SYLLOGISME_H

#include "listQuant.h"
#include <stdbool.h>

typedef struct
{
    bool U1, U2, Uc, A1, A2, Ac, S, P;
    char *quant1, *quant2, *quant3, *sujet, *predicat, *moyenTerme;
    int figure;
} syllogisme;

syllogisme *initSyllo();
void freeSyllo(syllogisme *s);
void printSyllo(syllogisme *s);

int askInt(int max);
char *askString();

void changeList(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d);

void saisie(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s);

void mode1(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s);
void mode2(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s);
bool mode2_1(syllogisme *s);
void mode2_2(syllogisme *s);
void mode2_3(syllogisme *s);
void detSyllo(char *s1, char *p1, syllogisme *s);
void askQuant(quantificateurs *a, quantificateurs *b, quantificateurs *c, quantificateurs *d, syllogisme *s, int num);
char *getListQuant(quantificateurs *list);
void scanfTypeFigure(syllogisme *s);

#endif
