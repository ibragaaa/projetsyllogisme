#ifndef LIST_QUANT_H
#define LIST_QUANT_H

#include <stdbool.h>
typedef struct
{
    bool U, A;
    char **l;
    int size;
} quantificateurs;

quantificateurs *initListQuant(bool u, bool a);
void freeListQuant(quantificateurs *list);
void addListQuant(quantificateurs *list, char *quant);
void printListQuant(quantificateurs *list);
void printListQuant2(quantificateurs *list);

#endif
