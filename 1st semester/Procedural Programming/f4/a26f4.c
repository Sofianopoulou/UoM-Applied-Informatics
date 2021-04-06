/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a26f4: Να δημιουργήσετε τις συναρτήσεις f() και g(), οι οποίες ορίζονται από
τους παρακάτω μαθηματικούς τύπους, οι οποίες θα πρέπει να υλοποιηθούν ως συναρτήσεις στην γλώσσα C:

    f(x)={x+2 , x>0
          −3x+7, x≤0}

    g(x,y)={x−y, x>0 και y>0
            7 x−5, αλλιώς}

Οι τιμές των παραμέτρων x,y στις παραπάνω συναρτήσεις είναι ακέραιες (int). Ο τύπος των συναρτήσεων θα
καθοριστεί από εσάς. Να υλοποιηθεί πρόγραμμα το οποίο ζητά από τον χρήστη τις παραμέτρους x και y, και
έπειτα εμφανίζει (α) το αποτέλεσμα της συνάρτησης f(x), (β) το αποτέλεσμα της συνάρτησης g(x,y) και το
αποτέλεσμα της συνάρτησης f(g(x)), όπως φαίνονται στα ακόλουθα παραδείγματα εκτέλεσης. Η εμφάνιση των
αποτελεσμάτων θα γίνεται μέσω του κυρίως προγράμματος (συνάρτηση main(), δηλαδή η εντολή εμφάνισης των
αποτελεσμάτων (printf) θα είναι στην main()).  */

#include <stdio.h>
#include "simpio.h"

int f(int x);
int g(int x, int y);
int fog(int x, int y);

int main()
{
    int x,y;

    printf("Enter x: ");
    x = GetInteger();
    printf("Enter y: ");
    y = GetInteger();
    printf("f(x) = f(%d) = %d \n", x, f(x));
    printf("g(x,y) = g(%d,%d) = %d \n", x, y, g(x,y));
    printf("f(g(x,y)) = f(g(%d,%d)) = %d \n", x, y, fog(x,y));

    system ("PAUSE");
    return 0;
}

int f(int x)
{
    int z;
    if(x>0){z = x+2;}
    else {z = -3*x+7;}
    return z;
}

int g(int x, int y)
{
    int z;
    if(x>0 && y>0){z = x-y;}
    else {z = 7*x-5;}
    return z;
}

int fog(int x, int y)
{
    int z;
    if(x>0 && y>0){z = x+2-y;}
    if(x>0 && y<0){z = 7*x-3;}
    if(x<=0 && y<=0) {z = 22-21*x;}
    return z;
}
