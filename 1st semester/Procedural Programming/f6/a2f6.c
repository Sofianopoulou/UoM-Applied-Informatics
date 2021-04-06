/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a2f6:
Να γραφεί ένα πρόγραμμα το οποίο διαβάζει μη-αρνητικούς ακέραιους αριθμούς (int) από το χρήστη (δεν χρειάζεται έλεγχος) και θα τους αποθηκεύει σε
ένα μονοδιάστατο πίνακα, μέγιστου μεγέθους 100. Το πρόγραμμα δέχεται αριθμούς από τον χρήστη μέχρι εκείνος να εισάγει την τιμή -1.
Έπειτα υπολογίζει το μέγιστο και ελάχιστο στοιχείο του πίνακα και εμφανίζει (από το κυρίως πρόγραμμα,, δηλαδή την συνάρτηση main())
κατάλληλο μήνυμα στην οθόνη όπως φαίνεται στο παράδειγμα εκτέλεσης.

Το πρόγραμμά σας θα πρέπει να έχει:
 μια συνάρτηση η οποία διαβάζει τους αριθμούς από τον χρήστη, αποθηκεύει στον πίνακα (όλους τους αριθμούς εκτός από το -1), και επιστρέφει
το πλήθος των τιμών που εισήγαγε ο χρήστης χωρίς να υπολογίζει την τιμή -1,
 μια συνάρτηση η οποία εντοπίζει και ενημερώνει την καλούσα συνάρτηση  συγχρόνως τόσο για τη μικρότερη όσο και για τη μεγαλύτερη τιμή ενός
μονοδιάστατου πίνακα ακεραίων, δηλαδή «επιστρέφει» (δείτε παρατήρηση 5 στην αρχή της άσκησης) δύο τιμές. */

#include <stdio.h>
#include "simpio.h"

#define N 100

int ReadData(int array[N]);
void Calculate(int array[N], int counter, int *max, int *min);

int main()
{
    int array[N];
    int max,min,counter;

    printf("Enter the elements of the array, one per line.\n");
    printf("Use -1 to signal the end of the list.\n");

    counter=ReadData(array);
    Calculate(array, counter, &max, &min);
    printf("The range of values is %d-%d",min,max);

    return 0;
}

int ReadData(int array[N])
{
    int num,i;

    for(i=0;i<N;i++)
    {
        printf("? ");
        num=GetInteger();
        if(num==-1) {break;}
        else {array[i]=num;}
    }
    return i;
}

void Calculate(int array[N], int counter, int *max, int *min)
{
    int i;
    *max = *min = array[0];
    for(i=1;i<counter;i++)
    {
        if (array[i] > *max)
            {*max=array[i];}
        if (array[i] < *min)
            {*min=array[i];}
    }

}


