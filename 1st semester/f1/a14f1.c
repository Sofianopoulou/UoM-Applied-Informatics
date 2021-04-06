/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a14f1:  Να γραφεί πρόγραμμα που θα υπολογίζει και θα εμφανίζει πόσες
θερμίδες χρειάζεται καθημερινά μια γυναίκα η οποία κάνει καθιστική ζωή. Η ενέργεια που
απαιτείται για το βασικό μεταβολισμό του γυναικείου οργανισμού, BMR, υπολογίζεται ως εξής:
BMR = 655 + (9.6 X Βάρος σε κιλά) + (1.8 X Ύψος σε cm) - (4.7 X Ηλικία σε χρόνια).*/

#include <stdio.h>
#include "simpio.h"

int main(){

    double Weight;
    int Height;
    int Age;
    double BMR;

    printf ("Dwse varos se kila: ");
    Weight = GetReal();
    printf ("Dwse upsos se cm: ");
    Height = GetInteger();
    printf ("Dwse ilikia se xronia: ");
    Age = GetInteger();

    BMR = 655 + (9.6*Weight) + (1.8*Height) - (4.7*Age);
    printf ("To BMR einai: %g", BMR);

      return 0;
}
