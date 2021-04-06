/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a11f5: Η Ε.Μ.Υ. καταγράφει ανά 8 ώρες τις θερμοκρασίες 10 πόλεων της Ελλάδος
(τα ονόματα των πόλεων είναι κωδικοποιημένα με αριθμούς: 0=Θεσσαλονίκη, 1=Αθήνα κλπ).
Να γραφεί πρόγραμμα που θα διαβάζει τις θερμοκρασίες (μεταβλητές τύπου double) ενός εικοσιτετραώρου για κάθε πόλη
(θερμοκρασία 0ου 8ώρου, 1ου 8ώρου, 2ου 8ώρου για κάθε πόλη).
Στη συνέχεια να υπολογίζει και να εμφανίζει:
 τον εθνικό μέσο όρο θερμοκρασίας (μεταβλητή τύπου double) και
 για κάθε πόλη τη μέση θερμοκρασία της και τη μέγιστη απόκλισή της από τον εθνικό μέσο όρο (μεταβλητές τύπου double).

Τα αποτελέσματα να εμφανίζονται με την παρακάτω μορφή:
εθνικός μέσος όρος θερμοκρασίας
City 0 μέση θερμοκρασία 0ης πόλης_μέγιστη απόκλιση της 0ης πόλης από τον εθνικό μέσο όρο
City 1μέση θερμοκρασία 1ης πόλης_μέγιστη απόκλιση της 1ης πόλης από τον εθνικό μέσο όρο
......................................
City 9 μέση θερμοκρασία 9ης πόλης_μέγιστη απόκλιση της 9ης πόλης από τον εθνικό μέσο όρο */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

#define CTS 10
#define S 3

int main()
{
    double devnat[CTS][S], temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg,max;
    int i,j;

    /*Read all Temperatures*/
    for(i=0;i<CTS;i++)
    {
        for(j=0;j<S;j++)
        {
           printf("Temp of City %d During %d 8-hour period: ", i,j);
           temper[i][j]=GetReal();
        }
    }

    /*Calculating the average of all Cities&Temps*/
    natavg=0;
    for(i=0;i<CTS;i++)
    {
        for(j=0;j<S;j++)
        {
            natavg = natavg + temper[i][j];
        }
    }
    natavg = natavg/(CTS*S);

    /*Calculating average temp on each city*/
    for(i=0;i<CTS;i++)
    {
        average[i]=0;
        for(j=0;j<S;j++)
        {
            average[i]+=temper[i][j];
        }
        average[i]=average[i]/S;
    }

    /*Calculating standard deviation*/
    for(i=0;i<CTS;i++)
    {
        for(j=0;j<S;j++)
        {
            devnat[i][j] = fabs(natavg-temper[i][j]);
        }
    }

    /*Calculating max deviation*/
    for(i=0;i<CTS;i++)
    {
        max = devnat[i][0];
        for(j=1;j<S;j++)
        {
            if(max < devnat[i][j])
                max = devnat[i][j];
            mdeviation[i]=max;
        }
    }

    printf("%3.1f\n",natavg);
    for(i=0;i<CTS;i++)
        printf("City %d  %.1f  %.1f\n",i,average[i],mdeviation[i]);

    return 0;
}
