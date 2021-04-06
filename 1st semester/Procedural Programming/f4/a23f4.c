/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a23f4: Γράψτε πρόγραμμα που περιλαμβάνει μια συνάρτηση με το όνομα Valid_Time
η οποία θα δέχεται ως τυπικές παραμέτρους 3 ακέραιους αριθμούς (int) που αντιστοιχούν σε ώρες, λεπτά και δευτερόλεπτα
μιας χρονικής στιγμής της ημέρας (ώρα) και θα επιστρέφει την τιμή ΤRUΕ ή FΑLSΕ ανάλογα με το αν η δοθείσα χρονική στιγμή
(ώρα) είναι έγκυρη ή όχι (αν δηλαδή οι ώρες θα πρέπει να είναι από 0 έως και 23 και τα λεπτά και δευτερόλεπτα να είναι από 0 έως και 59).
Τα δεδομένα (ώρες, λεπτά και δευτερόλεπτα) θα ζητούνται από τον χρήστη στο κυρίως πρόγραμμα, όπως φαίνεται στα ακόλουθα παραδείγματα.
Στο τέλος το πρόγραμμα θα εμφανίζει το μήνυμα “WRA EGKYRH” ή “WRA MH EGKYRH” από το κυρίως πρόγραμμα (συνάρτηση main(), δηλαδή η εντολή
εμφάνισης του μηνύματος (printf) θα είναι στην main). */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

bool Valid_Time(int hours, int min, int sec);

int main()
{
    int hours, min, sec;

    printf("Dwse tis ores: ");
    hours = GetInteger();
    printf("Dwse ta lepta: ");
    min = GetInteger();
    printf("Dwse ta defterolepta: ");
    sec = GetInteger();
    if (Valid_Time(hours,min,sec)) printf("WRA EGKYRH \n");
    else printf("WRA MH EGKYRH \n");

    system("PAUSE");
    return 0;
}

bool Valid_Time(int hours, int min, int sec)
{
    if(hours>0 && hours<23 && min>0 && min<59 && sec>0 && sec<59) return TRUE;
      return FALSE;
}
