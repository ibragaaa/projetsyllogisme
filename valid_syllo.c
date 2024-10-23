#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "valid_syllo.h"

void validSyllo(syllogisme *s)
{
    bool Rmt, Rlh, Rnn, Rn, Raa, Rpp, Rp, Ruu;
    Rnn = regle_Rnn(s); // si faux aret prog
    if (Rnn)
    {
        Rn = regle_Rn(s);
        Raa = regle_Raa(s);
    }

    if (Rnn && Rn)
    {
        printf("Syllogisme VALIDE \n");
    }
    else
    {
        printf("Syllogisme INVALIDE\n");
    }
}

bool regle_Rnn(syllogisme *s)
{
    // Rnn : deux prémisses négatives ne donnent pas de conclusion
    if (s->A1 || s->A2)
    {
        if (s->A1)
        {
            printf("Rnn. La premiere premisse est affirmative, donc Rnn est verifiee.\n");
        }
        else if (s->A2)
        {
            printf("Rnn. La deuxieme premisse est affirmative, donc Rnn est verifiee.\n");
        }
        return true;
    }
    else
    {
        printf("Deux premisse negative ne donne pas de conclusion\n");
        return false;
    }
}

bool regle_Rn(syllogisme *s)
{
    //  Rn : si une prémisse est négative, la conclusion est négative.
    if (!s->Ac)
    {
        if (s->A1 && s->A2)
        {
            printf("Rn. Les deux premisses sont positive et la conclusion est negative, donc Rnn n'est pas verifiee.\n");
            return false;
        }
        else
        {
            if (s->A1)
            {
                printf("Rn. La deuxieme premisse est negative et la conclusion est negative, donc Rnn est verifiee.\n");
            }
            else if (s->A2)
            {
                printf("Rn. La premiere premisse est negative et la conclusion est negative, donc Rnn est verifiee.\n");
            }
            return true;
        }
    }
}

bool regle_Raa(syllogisme *s)
{
    //  Raa : deux prémisses affirmatives donnent une conclusion affirmative.
    if (s->Ac)
    {
        if (s->A1 && s->A2)
        {
            printf("Rn. Les deux premisses sont pisitive et la conclusion l'est aussi, donc Rnn est verifiee.\n");
            return true;
        }
        else
        {
            if (s->A1)
            {
                printf("Rn. La deuxieme premisse est negative et la conclusion est positive, donc Rnn n'est pas verifiee.\n");
            }
            else if (s->A2)
            {
                printf("Rn. La premiere premisse est negative et la conclusion est positive, donc Rnn n'est pas verifiee.\n");
            }
            return false;
        }
    }
}
