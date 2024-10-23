#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "valid_syllo.h"

void validSyllo(syllogisme *s)
{
    bool Rmt, Rlh, Rnn, Rn, Raa, Rpp, Rp, Ruu;
    Rmt = regle_Rmt(s);
    Rlh = regle_Rlh(s);
    Rnn = regle_Rnn(s); // si faux aret prog
    if (Rnn)
    {
        Rn = regle_Rn(s);
        Raa = regle_Raa(s);
        Rpp = regle_Rpp(s);
        if (Rpp)
        {
            Rp = regle_Rp(s);
        }
    }

    if (Rmt && Rlh && Rnn && Rn && Raa && Rpp && Rp)
    {
        printf("Syllogisme VALIDE \n");
    }
    else
    {
        printf("Syllogisme INVALIDE\n");
    }
}
// A FAIRE **************************************************************************************************************
bool regle_Rmt(syllogisme *s)
{
}
// A FAIRE **************************************************************************************************************
bool regle_Rlh(syllogisme *s)
{
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
        printf("Rnn. Deux premisse negative ne donne pas de conclusion, donc Rnn n'est pas verifiee.\n");
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
            printf("Rn. Les deux premisses sont positive et la conclusion est negative, donc Rn n'est pas verifiee.\n");
            return false;
        }
        else
        {
            if (s->A1)
            {
                printf("Rn. La deuxieme premisse est negative et la conclusion est negative, donc Rn est verifiee.\n");
            }
            else if (s->A2)
            {
                printf("Rn. La premiere premisse est negative et la conclusion est negative, donc Rn est verifiee.\n");
            }
            return true;
        }
    }
    else
    {
        printf("Rn. Le syllogisme n'a pas de premisse et de conclusion negative, donc Rn est verifiee.\n");
        return true;
    }
}

bool regle_Raa(syllogisme *s)
{
    //  Raa : deux prémisses affirmatives donnent une conclusion affirmative.
    if (s->Ac)
    {
        if (s->A1 && s->A2)
        {
            printf("Raa. Les deux premisses sont positive et la conclusion l'est aussi, donc Raa est verifiee.\n");
            return true;
        }
        else
        {
            if (s->A1)
            {
                printf("Rn. La deuxieme premisse est negative et la conclusion est positive, donc Raa n'est pas verifiee.\n");
            }
            else if (s->A2)
            {
                printf("Rn. La premiere premisse est negative et la conclusion est positive, donc Raa n'est pas verifiee.\n");
            }
            return false;
        }
    }
    else
    {
        printf("Raa. Le syllogisme n'a pas deux premisses affirmatives, donc Raa est verifiee.\n");
        return true;
    }
}

bool regle_Rpp(syllogisme *s)
{
    // Rpp : deux prémisses particulières ne donnent pas de conclusion.
    if (s->U1 || s->U2)
    {
        if (s->U1 && s->U2)
        {
            printf("Rpp. Le syllogisme n'a aucune premisse particuliere donc Rpp est verifiee. \n");
        }
        else if (s->U1)
        {
            printf("Rpp. Le syllogisme n'a qu'une premisse particuliere (la seconde) donc Rpp est verifiee. \n");
        }
        else if (s->U2)
        {
            printf("Rpp. Le syllogisme n'a qu'une premisse particuliere (la premiere) donc Rpp est verifiee. \n");
        }
        return true;
    }
    else
    {
        printf("Rpp. Le syllogisme a deux premisse particuliere donc Rpp n'est pas verifiee. \n");
        return false;
    }
}

bool regle_Rp(syllogisme *s)
{
    //  Rp : si une prémisse est particulière la conclusion est particulière.
    if (!s->Uc)
    {
        if (!s->U1)
        {
            printf("Rp. La premiere premisse est particuliere et la conclusion est particuliere, donc Rp est verifiee.\n");
            return true;
        }
        else if (!s->U2)
        {
            printf("Rp. La seconde premisse est particuliere et la conclusion est particuliere, donc Rp est verifiee.\n");
            return true;
        }
        else
        {
            printf("Rp. Les deux premisses ne sont pas particuliere et la conclusion est particuliere, donc Rp n'est pas verifiee\n");
            return false;
        }
    }
    else
    {
        if (!s->U1)
        {
            printf("Rp. La premiere premisse est particuliere et la conclusion n'est pas particuliere, donc Rp n'est pas verifiee.\n");
            return false;
        }
        else if (!s->U2)
        {
            printf("Rp. La seconde premisse est particuliere et la conclusion n'est pas particuliere, donc Rp n'est pas verifiee.\n");
            return false;
        }
        else
        {
            printf("Rp. Les premisses ne sont pas particuliere et la conclusion n'est pas particuliere, donc Rp est verifiee.\n");
            return true;
        }
    }
}
