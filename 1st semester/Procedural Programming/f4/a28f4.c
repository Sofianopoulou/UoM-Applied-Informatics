/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a27f4: Να γράψετε πρόγραμμα που θα διαβάζει τον κωδικό και την τιμή ενός αγνώστου πλήθους προϊόντων που αγόρασε κάποιος σε ένα πολυκατάστημα.
Ο κωδικός θα πρέπει να είναι στο διάστημα [0..2000] και να γίνεται ο αντίστοιχος έλεγχος από το πρόγραμμα. Η είσοδος των δεδομένων (κωδικός και τιμή) θα συνεχίζεται
μέχρι να δοθεί ως κωδικός το μηδέν (δείτε παράδειγμα εκτέλεσης).

Έκπτωση Στην περίοδο των εκπτώσεων γίνεται σε κάθε προϊόν έκπτωση ανάλογα με τον κωδικό του, ως εξής:
Κωδικός προϊόντος Ποσοστό έκπτωσης
    1..300               5%
    301..500            10%
    501..1000           15%
    1001..2000          20%

Υπολογισμός Πόντων
Για κάθε προϊόν δίνονται κάποιοι πόντοι, τους οποίους ο πελάτης εξαργυρώνει με διάφορα δώρα.
Συγκεκριμένα, για κάθε προϊόν δίνεται:
• ένας πόντος ανεξάρτητα από την τιμή του και
• επιπλέον για τα προϊόντα με κωδικό από 1000 έως και 1500 ένας πόντος για κάθε 5 Ευρώ της τελικής αξίας του προϊόντος. (δηλαδή της αξίας που προκύπτει μετά την έκπτωση).
Οι επιπλέον πόντοι υπολογίζονται από τον τύπο επιπλέον_πόντοι = ceil(τελική αξία/5)

Για παράδειγμα:

Για ένα προϊόν με κωδικό 1200 και τιμή 100€:
• η τελική τιμή θα είναι: 80€
• το ποσό της έκπτωσης: 20€
• οι πόντοι: 17
Για ένα προϊόν με κωδικό 100 και τιμή 10€:
• η τελική τιμή θα είναι: 9.50€ • το ποσό της έκπτωσης: 0.50€
• οι πόντοι: 1
Το πρόγραμμα θα εμφανίζει στην οθόνη τα ακόλουθα:
• το τελικό σύνολο που θα πληρώνει ο πελάτης (μετά την έκπτωση)
• το συνολικό ποσό έκπτωσης
• το σύνολο των πόντων */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

int get_code();
int  product_points(int code, double price);
double discount_percentage(int code);

int main()
{
    int code, points;
    double price, finalPrice, discount, total, discountSum;

    total = discountSum = 0;
    points = 0;

    while((code = get_code()))
    {
        printf("Dwse thn timh: ");
        price = GetReal();
        discount = discount_percentage(code)*price;
        discountSum += discount;
        finalPrice = price - discount;
        total += finalPrice;
        points += product_points(code, finalPrice);
    }

    printf("------------------\n");
    printf("Teliko synolo: %.2f Euro\n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);

    system("PAUSE");
    return 0;
}

int get_code()
{
    int code;
    while(TRUE)
    {
        printf("Dwse ton kwdiko: ");
        code = GetInteger();
        if (code>=0 && code <=2000)
            return code;
        printf("Lathos Kwdikos (0-2000)\n");
    }
}

double discount_percentage(int code)
{
    if (code<=300) return 0.05;
    else if(code<=500) return 0.10;
    else if(code<=1000) return 0.15;
    else return 0.20;
}

int  product_points(int code, double fPrice)
{
    int points = 1;
    if (code>=1000 && code<=1500)
        points += ceil(fPrice/5);
    return points;
}
