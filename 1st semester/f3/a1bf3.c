/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a1bf3: Να γράψετε πρόγραμμα για κάθε μία από τις παρακάτω περιπτώσεις:
a. Ο σημερινός αριθμός αυτοκινήτων που κυκλοφορούν σε μια πόλη είναι 80000. Αν ο αριθμός
αυτός αυξάνεται με ρυθμό 7%, να γραφεί πρόγραμμα που να υπολογίζει σε πόσα χρόνια ο αριθμός
των αυτοκινήτων θα ξεπεράσει τις 160000. Πόσα θα είναι τότε τα αυτοκίνητα;
b. Γενικεύστε το πρόγραμμα για Αrithmo_Αytok (long) αυτοκίνητα, που αυξάνονται με ετήσιο ρυθμό
Rythmos και ξεπερνούν ένα δοσμένο όριο Οrio (long), στοιχεία τα οποία θα εισάγει ο χρήστης.

Τα προγράμματα a και b να εμφανίζουν τα έτη (long) και τον αριθμό των αυτοκινήτων (long) όταν θα ξεπεράσει το δοσμένο όριο.
Για τον υπολογισμό του ετήσιου αριθμού αυτοκινήτων να χρησιμοποιηθεί ο τύπος:
Αριθμός αυτοκινήτων = ceil(Αριθμός αυτοκινήτων *(1+Ρυθμός αύξησης)) */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

int main(){

    long initial_cars;
    double rate;
    long limit;
    long cars;
    long years;

    printf("Dwse ton arxiko arithmo autokinhtwn:");
    initial_cars = GetLong();
    printf("Dwse ton ethsio rythmo ayxhshs:");
    rate = GetReal();
    printf("Dwse to orio:");
    limit = GetLong();

    years = 0;
    cars = initial_cars;
    while (cars <= limit)
    {
        cars = ceil(cars*(1+rate));
        years++;
    }

    printf("After %ld years number of Cars is %ld. \n", years, cars);
    //system("PAUSE");
    return 0;

}
