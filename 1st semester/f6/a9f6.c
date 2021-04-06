/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a9f6:
Μια εταιρεία εμπορεύεται 5 προϊόντα αξίας 250, 150, 320, 210 και 920 ευρώ αντίστοιχα.
Η πώληση των παραπάνω προϊόντων γίνεται μέσω 4 πωλητών. Ο παρακάτω πίνακας δίνει τις πωλήσεις που έγιναν μέσα σε μια βδομάδα:

Α/Α Πωλητή      Προϊόν 0    Προϊόν 1    Προϊόν 2    Προϊόν 3    Προϊόν 4
    0               10         4            5           6           7
    1                7         0            12          1           3
    2                4         19            5          0           8
    3                3          2            1          5           6

Αν ο πίνακας πωλήσεων είναι δεδομένος και σταθερός, και οι τιμές των προϊόντων είναι αποθηκευμένες σε σταθερό πίνακα κατάλληλης διάστασης,
να γραφεί πρόγραμμα που θα:
 υπολογίζει και θα αποθηκεύει στον πίνακα salesPerson[] το συνολικό ποσό είσπραξης (int) για κάθε πωλητή, μέσω μιας συνάρτησης calculateSales()
 υπολογίζει και θα αποθηκεύει στον πίνακα productSale[] τις ποσότητες (int) που πουλήθηκαν από κάθε προϊόν, μέσω μιας συνάρτησης calculateProductSales()
 θα τυπώνει τις συνολικές πωλήσεις κάθε πωλητή και τις συνολικές πωλήσεις κάθε προϊόντος,
 Τον πωλητή με τις μεγαλύτερες (σε έσοδα) πωλήσεις και τα έσοδα του και το προϊόν με τις περισσότερες πωλήσεις και πόσα τεμάχια πούλησε.

Για τους παραπάνω υπολογισμούς να υλοποιήσετε
 μια συνάρτηση maxArray() η οποία θα δέχεται ένα μονοδιάστατο πίνακα, το μέγεθός του (αριθμό στοιχείων)
και θα επιστρέφει το μέγιστό του στοιχείο (int) και την θέση του στον πίνακα (int),
 μια συνάρτηση printArray() η οποία δέχεται ένα πίνακα, την
διάσταση του και θα τυπώνει τον πίνακα στην οθόνη σε δύο στήλες, όπου στην πρώτη στήλη θα δίνεται η θέση του στοιχείου στον πίνακα και στη δεύτερη η τιμή του*/

#include <stdio.h>
#include "simpio.h"

#define SALESMEN 4
#define PRODUCTS 5

void calculateSales(int S, int P, int salesTable[S][P], int price[P], int sp[S]);
void calculateProductSales(int S, int P, int salesTable[S][P], int prods[P]);
void maxArray(int size, int table[size], int *max, int *pos);
void printArray(int size, int table[]);

int main()
{
    int price[PRODUCTS]={250,150,320,210,920};
    int sales[SALESMEN][PRODUCTS]=
                {
                    {10,4,5,6,7},
                    {7,0,12,1,3},
                    {4,19,5,0,8},
                    {3,2,1,5,6}
                };
    int salesPerson[SALESMEN];
    int productSale[PRODUCTS];
    int MaxSalesMan,MaxProduct;
    int income,items;

    calculateSales(SALESMEN,PRODUCTS,sales,price,salesPerson);
    calculateProductSales(SALESMEN,PRODUCTS,sales,productSale);
    maxArray(SALESMEN, salesPerson, &income, &MaxSalesMan);
    maxArray(PRODUCTS, productSale, &items, &MaxProduct);

    printf("SalesMan-Sales \n");
    printArray(SALESMEN, salesPerson);
    printf("Best Salesman was %d with %d sales\n", MaxSalesMan, income);
    printf("Product-Items \n");
    printArray(PRODUCTS, productSale);
    printf("Best Product was %d with %d items\n", MaxProduct, items);

    return 0;
}

void calculateSales(int S, int P, int salesTable[S][P], int price[P], int sp[S])
{
    int i,j;
    for(i=0;i<S;i++)
    {
        sp[i]=0;
        for(j=0;j<P;j++)
            sp[i] += salesTable[i][j] * price[j];
    }

}

void calculateProductSales(int S, int P, int salesTable[S][P], int prods[P])
{
    int i,j;
    for(j=0;j<P;j++)
    {
        prods[j]=0;
        for(i=0;i<S;i++)
            prods[j] += salesTable[i][j];
    }
}

void maxArray(int size, int table[], int *max, int *pos)
{
    int i;
    *max = table[0];
    *pos = 0;
    for(i=1;i<size;i++)
    {
        if (table[i] > *max)
        {
            *max = table[i];
            *pos = i;
        }
    }
}

void printArray(int size, int table[])
{
    int i;
    for(i=0;i<size;i++)
        printf("%d\t%d\n",i,table[i]);
}



