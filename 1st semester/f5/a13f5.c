/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a13f5: Να γραφεί πρόγραμμα το οποίο:
(α) Θα ζητά από τον χρήστη δύο θετικούς ακέραιους αριθμούς R (γραμμές) και C (στήλες) από το 1 μέχρι και το 10. Μπορείτε να υποθέσετε με ασφάλεια ότι ο χρήστης θα εισάγει
σωστούς αριθμού σύμφωνα με τα προηγούμενα όρια. Δεν απαιτείται έλεγχος. Η εισαγωγή θα γίνεται από την συνάρτηση main.
(β) Θα "γεμίζει" τα στοιχεία R x C ενός διδιάστατου πίνακα Α ακεραίων (διάστασης 10x10) με τυχαίους ακέραιους από 0 έως και 99 (rand() % 100),
μέσω κλήσης μιας συνάρτησης populate_data. Δηλαδή το πρόγραμμα θα χρησιμοποιεί μέρος του πίνακα Α, βάσει των αριθμών R και C, που εισήγαγε ο χρήστης.
(γ) Θα καλεί μια συνάρτηση print_array που θα τυπώνει τα R x C στοιχεία του πίνακα Α.
(δ) Θα καλεί μια διαδικασία change_array, η οποία για κάθε γραμμή του
πίνακα Α θα θέτει όσα στοιχεία είναι αριστερά του μέγιστου της γραμμής ίσα με αυτό (δηλαδή όσα είναι στην ίδια γραμμή με αυτό, αλλά έχουν μικρότερο δείκτη στήλης θα γίνουν ίσα με το μέγιστο).
(ε) Τέλος, θα εμφανίζονται και πάλι τα στοιχεία του "αλλαγμένου" πίνακα κατά γραμμές. Όλες οι συναρτήσεις σας θα ακολουθούν το πρότυπο C99 για πίνακες
2 διαστάσεων. ΠΡΟΣΟΧΗ στις δηλώσεις των παραμέτρων των συναρτήσεων. Είναι άλλο η διάσταση του πίνακα, και άλλο ποιο μέρος του πίνακα έχει χρησιμοποιηθεί. θα πρέπει να περάσετε περισσότερες παραμέτρους. */

#include <stdio.h>
#include "simpio.h"

#define N 10

void populate_data(int R, int C, int array[N][N]);
void print_array(int R, int C, int array[N][N]);
void change_array(int R, int C, int array[N][N]);

int main()
{
    int R,C;
    int array[N][N];

    printf("Dwse ton arithmo twn grammwn: ");
    R=GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    C=GetInteger();

    populate_data(R,C,array);
    print_array(R, C, array);
    change_array(R,C,array);
}

void populate_data(int R, int C, int array[N][N])
{
    int i,j;
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
    {
        array[i][j] = rand()%100;
    }
}

void print_array(int R, int C, int array[N][N])
{
    int i,j;
    printf("ARXIKOS PINAKAS\n");
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {printf("%2d ", array[i][j]);}
        printf("\n");
    }
}

void change_array(int R, int C, int array[N][N])
{
    int i,j,k,max;
    int max_number[R];
    int pointer[R];

    for(i=0;i<R;i++)
    {
        max=0;
        for(j=0;j<C;j++)
        {
            if (array[i][j]>max)
            {
                max=array[i][j];
                max_number[i]=max;
                pointer[i]=j;
            }
        }
    }

    for(i=0;i<R;i++)
        for(k=0;k<pointer[i];k++)
        array[i][k]=max_number[i];

    printf("ALLAGMENOS PINAKAS\n");
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {printf("%2d ", array[i][j]);}
        printf("\n");
    }
}



