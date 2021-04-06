/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a4f1:  Ένας έμπορος αγόρασε σε τιμή χονδρικής εμπορεύματα αξίας purchaseAmount €
και τα πούλησε saleAmount €. Αν το ποσό saleAmount προκύπτει από την καθαρή αξία purchaseAmount
και το ποσοστό κέρδους rate του εμπόρου επί της καθαρής αξίας purchaseAmount, να γίνει πρόγραμμα
που να υπολογίζει και να εμφανίζει: α) το κέρδος του εμπόρου profit (double), β) το εισπραχθέν
ποσό saleAmount (double). Τα δεδομένα εισόδου να έχουν τη μορφή: purchaseAmount (μεταβλητή τύπου long)
rate (μεταβλητή τύπου int, εάν το ποσοστό κέρδους είναι 10% τότε πληκτρολογούμε 10) */

#include <stdio.h>
#include "simpio.h"

int main(){

    long purchaseAmount;
    int rate;
    double salesAmount;
    double profit;

    printf("Dwse thn katharh axia: ");
    purchaseAmount = GetLong();
    printf("Dwse to pososto kerdous:");
    rate = GetInteger();


    profit = purchaseAmount * ((double) rate / 100.0);
    salesAmount = purchaseAmount + profit;


    printf("To kerdos einai %g\n", profit);
    printf("To synoliko poso einai %g", salesAmount);

      return 0;
}
