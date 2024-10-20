#include <stdio.h>
#include <stdlib.h>
#include "syllogisme.h"

#include <string.h>

int main()
{
    Syllogysme *s = initSyllo();
    askSylo(s);
    freeSyllo(s);

    return 0;
}
