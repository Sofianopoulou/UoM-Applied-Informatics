/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a7f2: Να γραφεί ένα πρόγραμμα C για τον υπολογισμό και την εμφάνιση της εβδομαδιαίας αμοιβής ενός εργαζομένου ως εξής:
Το πρόγραμμα θα διαβάζει τον κωδικό αριθμό (long) του εργαζομένου. Αν ο κωδικός αριθμός είναι μεγαλύτερος ή ίσος του 1000, τότε το πρόγραμμα
θα διαβάζει τον ετήσιο μισθό του εργαζομένου (double) και θα υπολογίζει την εβδομαδιαία αμοιβή (double) του διαιρώντας τον ετήσιο μισθό δια 52.
Αν ο κωδικός είναι μικρότερος του 1000, τότε το πρόγραμμα θα διαβάζει τις ώρες εβδομαδιαίας εργασίας (int) του εργαζομένου, την αμοιβή ανά ώρα (double)
και στη συνέχεια θα υπολογίζει την εβδομαδιαία αμοιβή. Αν η εβδομαδιαία εργασία είναι άνω των 40 ωρών, τότε για τις ώρες πέρα των 40 ωρών η αμοιβή έχει προσαύξηση 50%.*/

#include <stdio.h>
#include "simpio.h"

int main()
{
    long Code;
    double Salary, Wage, Weekly_amount;
    int Hours;

    printf("Dwse ton kwdiko:");
    Code = GetLong();

    if (Code >= 1000)
    {
         printf("Dwse ton ethsio mistho:");
         Salary = GetReal();
         Weekly_amount = Salary/52.0;
    }
    else
    {
         printf("Dwse tis wres ebdomadiaias ergasias:");
         Hours = GetInteger();
         printf("Dwse thn amoibh ana wra:");
         Wage = GetReal();
           if (Hours <= 40)
               {Weekly_amount = Hours*Wage;}
           else
               {Weekly_amount = 40*Wage + (Hours-40)*Wage*1.5;}
    }

     printf("H ebdomadiaia amoibh einai: %g\n", Weekly_amount);

     return 0;
}
