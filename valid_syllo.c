#include "valid_syllo.h"

void validSyllo(syllogisme *s)
{
    bool Rmt, Rlh, Rnn, Rn, Raa, Rpp, Rp, Ruu Rnn = regle_Rnn(s);
    Rn = regle_Rn(s);

    if (Rmt && Rlh && Rnn && Rn && Raa && Rpp && Rp && Ruu)
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
            printf("Rnn. La première prémisse est affirmative, donc Rnn est vérifiée.\n");
        }
        else if (s->A2)
        {
            printf("Rnn. La deuxième prémisse est affirmative, donc Rnn est vérifiée.\n");
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
    if ((!s->A1 || !s->A2) && !s->Ac)
    {
        return true;
    }
    else
    {
        if (!s->A1 || !s->A2)
        {
            if (!s->A1)
            {
                printf("A1 est negatif et A2 est positif");
            }
            if (!s->A2)
            {
                printf("A2 est negatif et A1 est positif");
            }
            printf(" donc la conclusion doit etre negative\n");
        }
        else
        {
            printf("A1 et A2 ne sont pas des premisses negatives donc la conclusion ne peut pas etre negative\n");
        }
        return false;
    }
}
