/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a13f6: Να γραφεί μια συνάρτηση decompose τύπου void, η οποία θα δέχεται ως όρισμα έναν ακέραιο (long)
και θα ενημερώνει την καλούσα συνάρτηση («επιστρέφει» - δείτε παρατήρηση 5 στην αρχή της άσκησης) για τα ακόλουθα:
 το πλήθος των ψηφίων του,
 τον μέσο όρο των ψηφίων του,
 το μέγιστο ψηφίο του.
Να υλοποιήσετε ένα πρόγραμμα το οποίο στη συνάρτηση main() θα ζητά από τον χρήστη ένα αριθμό (μηαρνητικός ακέραιος-δεν απαιτείται έλεγχος),
και χρησιμοποιεί την παραπάνω συνάρτηση για να εμφανίσει (από τη συνάρτηση main()) τα παραπάνω στοιχεία του αριθμού. Ο μέσος όρος θα εμφανίζεται
με ακρίβεια 3 δεκαδικών ψωφίων.*/

#include <stdio.h>
#include "simpio.h"

void decompose(long num, int *digits, int *max, double *average);

int main()
{
    long num;
    double average;
    int digits, max;

    printf("Please insert non-negative number:");
    num=GetLong();

    decompose(num, &digits, &max, &average);
    printf("Digits: %d\nAverage: %.3f\nMax: %d", digits, average, max);

    return 0;
}

void decompose(long num, int *digits, int *max, double *average)
{
    double sum;
    sum = 0;
    *digits = *average = *max = 0;

    if (num!=0)
    {
        while (num!=0)
        {
            sum += num%10;
            if (num%10 > *max) {*max = num%10;}
            num /= 10;
            *digits+=1;
        }

    *average = sum / *digits;
    }

    else if ((num=0))
    {
        *digits = 0;
        *average = 0;
        *max = 0;
    }
}
