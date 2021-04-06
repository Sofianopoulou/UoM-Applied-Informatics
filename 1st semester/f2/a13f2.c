/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a13f2:  Μία μηχανή αυτόματης πώλησης καφέ δέχεται μόνο ΕΝΑ χαρτονόμισμα των 5 € κάθε φορά και δίνει τα ρέστα σε κέρματα των 10, 20 & 50
λεπτών καθώς και σε κέρματα του 1 και 2 ευρώ . Κάθε καφές κοστίζει 70 λεπτά. Να γραφεί πρόγραμμα το οποίο να ζητάει τον αριθμό των καφέδων (int) και να
εμφανίζει τα ρέστα (σε κέρματα) (int) που πρέπει να δώσει από το χαρτονόμισμα των 5€. Στην περίπτωση που τα χρήματα δεν επαρκούν εμφανίζει το κατάλληλο μήνυμα.
(Τα χρήματα υπολογίζονται σε λεπτά του ευρώ).*/

#include <stdio.h>
#include "simpio.h"

int main()
{
    int number, resta, L10, L20, L50, E1, E2;

    printf("Dose kafedes:");
    number = GetInteger();
    if (number>7)
    {
        printf ("den ftanoun ta xrhmata gia tosous kafedes \n");
    }
    else
    {
        resta = 500 - number*70;
        E2 = resta/200;
        resta -= E2*200;
        E1 = resta/100;
        resta -= E1*100;
        L50 = resta/50;
        resta -= L50*50;
        L20 = resta/20;
        resta -= L20*20;
        L10 = resta/10;
        printf("Resta \n Kermata 2E :%d\n Kermata 1E :%d\n Kermata 50L :%d\n Kermata 20L :%d\n Kermata 10L :%d\n", E2, E1, L50, L20, L10);
    }

    return 0;
}
