/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a16f5: Να αναπτυχθεί (με τη χρήση των συναρτήσεων που περιγράφονται) πρόγραμμα στο οποίο,
- θα γεμίζει τον πίνακα a μεγέθους 50 με τυχαίους αριθμούς από το 0 έως το 9 χρησιμοποιώντας την συνάρτηση rand() (a[i]=rand() % 10),
της βιβλιοθήκης <stdlib.h> (συνάρτηση populate)
- θα εμφανίζει τον πίνακα a στην οθόνη (συνάρτηση printArr),
- θα ζητά έναν ακέραιο αριθμό Ν από το 0 έως και το 9 από τον χρήστη - δεν απαιτείται έλεγχος,
- θα καλεί την συνάρτηση checkTable, η οποία θα υπολογίζει τον αριθμό των εμφανίσεων του αριθμού Ν στον πίνακα a και τις θέσεις του πίνακα στις οποίες εμφανίζεται ο αριθμός
- θα εμφανίζει τα αποτελέσματα στο χρήστη, όπως φαίνεται στο παράδειγμα εκτέλεσης. Η εμφάνιση των αποτελεσμάτων θα γίνεται από τη συνάρτηση main() (κυρίως πρόγραμμα),
και των θέσεων που εμφανίζεται ο αριθμός Ν καλώντας την printArr */

#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"

#define W 50

void populate(int r, int a[r]);
void printArr(int r, int a[r]);
int checkTable(int r, int N, int a[r], int index[r]);

int main()
{
    int a[W],index[W];
    int N;

    populate(W,a);
    printArr(W,a);
    printf("\nDose arithmo apo to 0 ews to 9: ");
    N=GetInteger();
    printf("\no Arithmos %d emfanizetai %d fores.\nStis Theseis:\n",N,checkTable(W,N,a,index));
    printArr(checkTable(W,N,a,index),index);
    printf("\n");

    system("PAUSE");
    return 0;

}

void populate(int r, int a[r])
{
    int i;
    for(i=0;i<r;i++)
        a[i]=rand()%10;
}

void printArr(int r, int a[r])
{
    int i;
    for(i=0;i<r;i++)
        printf("%d  ",a[i]);
    printf("\n-------------");
}

int checkTable(int r, int N, int a[r], int index[r])
{
    int i,sum;

    sum=0;
    for(i=0;i<r;i++)
    {
        if ((a[i]==N))
        {index[sum]=i;
         sum++;}

    }
    return sum;
}


