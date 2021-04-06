/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a20f3: Γράψτε ένα πρόγραμμα που να διαβάζει μια σειρά από ηλικίες ανθρώπων
(ακολουθία αριθμών int που εισάγεται από το χρήστη) και να βρίσκει την μικρότερη και τη μεγαλύτερη ηλικία.
Το πρόγραμμα θα συνεχίζει να διαβάζει ηλικίες μέχρι να δοθεί ως ηλικία ο αριθμός -1. */

#include <stdio.h>
#include "simpio.h"

int main()
{
    int age, max, min;

    printf("Dwse ilikia:");
    age = GetInteger();
    max = age;
    min = age;

    while(age !=-1)
    {
    max = (age>max) ? age:max;
    min = (age<min) ? age:min;

    printf("Dwse ilikia:");
    age = GetInteger();
    }

    printf("H megalyteri ilikia einai %d\n", max);
    printf("H mikroteri ilikia einai %d", min);
    return 0;
}
