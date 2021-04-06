/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a5f1:  Να γραφεί πρόγραμμα που διαβάζει τις ώρες εργασίας (int), την ωριαία αντιμισθία (long)
και το ποσοστό (double) των κρατήσεων ενός εργάτη και στη συνέχεια υπολογίζει κι εμφανίζει τις ακαθάριστες αποδοχές του (double),
το ποσό των κρατήσεων (double) που έχει και τις καθαρές του αποδοχές (double). Ο υπολογισμός των ποσών θα γίνεται ως εξής:
Καθ. Αποδοχές= ώρες * ωριαία αντιμισθία κρατήσεις= καθαρές αποδοχές * ποσοστό ακαθάριστες αποδοχές= καθαρές αποδοχές + κρατήσεις*/

#include <stdio.h>
#include "simpio.h"

int main(){

    int WorkingHours;
    long HourlyWages;
    double HoldRate;
    double GrossEarnings;
    double HoldAmount;
    double NetEarnings;

    printf ("Dwse ton arithmo twn wrwn: ");
    WorkingHours = GetInteger();
    printf ("Dwse thn wriaia antimisthia: ");
    HourlyWages = GetLong();
    printf ("Dwse to pososto twn krathsewn: ");
    HoldRate = GetReal();

    NetEarnings = WorkingHours*HourlyWages;
    HoldAmount = NetEarnings*HoldRate;
    GrossEarnings = NetEarnings + HoldAmount;

    printf ("Oi akatharistes apodoxes einai %g\n", GrossEarnings);
    printf ("Oi krathseis einai %g\n", HoldAmount);
    printf ("Oi kathares apodoxes einai %g\n", NetEarnings);

      return 0;
}















