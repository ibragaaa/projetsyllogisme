#include <stdio.h>
#include <stdlib.h>
#include "syllogisme.h"

#include <string.h>

int main()
{
    /*init les listes de quantificateurs */
    /*********************************************UNIVERSELLES***************************************************/
    quantificateurs *universelle = initListQuant(true, true);
    addListQuant(universelle, "Tout");
    addListQuant(universelle, "Tous");
    addListQuant(universelle, "Chaque");
    addListQuant(universelle, "Chacun(e)");
    addListQuant(universelle, "N'importe quel(le)");
    addListQuant(universelle, "Quiconque");
    addListQuant(universelle, "Peu importe qui");
    addListQuant(universelle, "Peu importe quoi");
    addListQuant(universelle, "Qui que ce soit");
    addListQuant(universelle, "Quel(le) que soit");
    addListQuant(universelle, "Quoi que");
    addListQuant(universelle, "Ou que");

    /*********************************************UNIVERSELLES NEGATIVES***************************************************/
    quantificateurs *universelle_negatif = initListQuant(true, false);
    addListQuant(universelle_negatif, "Personne");
    addListQuant(universelle_negatif, "Rien");
    addListQuant(universelle_negatif, "Aucun");

    /*********************************************EXISTENCIELLES***************************************************/
    quantificateurs *existentielle = initListQuant(false, true);
    addListQuant(existentielle, "Quelqu'un");
    addListQuant(existentielle, "Quelque chose");
    addListQuant(existentielle, "Certains / Certaines");
    addListQuant(existentielle, "Un(e)");
    addListQuant(existentielle, "Il existe");
    addListQuant(existentielle, "Il y a");
    addListQuant(existentielle, "Un(e) certain(e)");
    addListQuant(existentielle, "Au moins un(e)");
    addListQuant(existentielle, "Quel que");
    addListQuant(existentielle, "Parfois");

    /*********************************************EXISTENCIELLES NEGATIVES***************************************************/
    quantificateurs *existentielle_negatif = initListQuant(false, false);
    addListQuant(existentielle_negatif, "Pas tout le monde");
    addListQuant(existentielle_negatif, "Pas toujours");

    /*initialisation du Syllogisme*/
    syllogisme *s = initSyllo();

    /*changer les listes */
    changeList(universelle, universelle_negatif, existentielle, existentielle_negatif);

    /*Saisie du Syllogisme*/
    saisie(universelle, universelle_negatif, existentielle, existentielle_negatif, s);

    /*destruction du Syllogisme*/
    freeSyllo(s);

    /*destruction des listes de quantificateurs*/
    freeListQuant(universelle);
    freeListQuant(universelle_negatif);
    freeListQuant(existentielle);
    freeListQuant(existentielle_negatif);

    return 0;
}
