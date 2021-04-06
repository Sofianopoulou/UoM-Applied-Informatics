/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a22f5: Γράψτε ένα πρόγραμμα που θα ελέγχει την εγκυρότητα των αριθμών πιστωτικών καρτών.
Το πρόγραμμα θα διαβάζει ένα δεκαεξαψήφιο ακεραίο (τύπου long long - δείτε διευκρίνιση στο τέλος της άσκησης*)
από τον χρήστη (με την συνάρτηση GetLongLong())* και θα τυπώνει τον αριθμό της κάρτας ακολουθούμενο από τη λέξη "VALID"
αν αυτός είναι έγκυρος αριθμός πιστωτικής κάρτας ή τη λέξη "invalid" διαφορετικά, σύμφωνα με τα μηνύματα που εμφανίζονται παρακάτω.
Για την υλοποίηση της άσκησης θα δημιουργήσετε ένα πίνακα τύπου long long, μεγέθους 16, στον οποίο σε κάθε θέση του πίνακα θα βάλετε
ένα ψηφίο του κωδικού.

Ο έλεγχος εγκυρότητας του κάθε δεκαεξαψήφιου αριθμού γίνεται σύμφωνα με τα ακόλουθα:
• Αν το πρώτο ψηφίο είναι μικρότερο από 4 ή μεγαλύτερο από 7, η κάρτα χαρακτηρίζεται ως μη έγκυρη.
• Αν ο αριθμός δεν έχει ακριβώς 16 ψηφία τότε η κάρτα είναι μη έγκυρη.

• Διαφορετικά:
◦   Διπλασιάζουμε (μόνο) τα ψηφία που βρίσκονται στις περιττές θέσεις του αριθμού (δηλαδή τα 1ο, 3ο, 5ο,..., 15ο, όπως φαίνονται στο παράδειγμα εκτέλεσης με κίτρινο χρώμα).
        Όσα από αυτά γίνουν διψήφια, προσθέτουμε τα ψηφία τους για να γίνουν μονοψήφια.
        Παραδείγματα: ▪ αρχικό ψηφίο 4, 2*4=8 άρα νέο ψηφίο 8. ▪ αρχικό ψηφίο 7, 2*7=14 άρα νέο ψηφίο 1+4 =5.
◦   Υπολογίσουμε το άθροισμα όλων των νέων ψηφίων που προκύπτουν (δηλαδή τόσο εκείνα σε περιττές θέσεις μετά τις αλλαγές όσο και εκείνα στις άρτιες).
        Αν το άθροισμα των 16 ψηφίων είναι ακέραιο πολλαπλάσιο του 10, η κάρτα είναι έγκυρη. και σε διαφορετική περίπτωση μη έγκυρη. */

#include <stdio.h>
#include "simpio.h"
#include "genlib.h"

#define N 16

long long GetLongLong(void);
int check_digits(long long code);
void card_digits_in_array(long long code, long long array[]);
bool check_card_validation(long long array[], long long code);

int main()
{
    long long code;
    long long array[N];

    printf("Insert card number:");
    code=GetLongLong();

    /* entry of card's digits in array*/
    card_digits_in_array(code,array);

    /* check card validation*/
    if (check_card_validation(array,code))
        printf("%lld is VALID",code);
    else printf("%lld is invalid ", code);

    return 0;
}

int check_digits(long long code)
{
    int digits=0;
    while (code!=0)
    {
        code /= 10;
        digits++;
    }
    return digits;
}

void card_digits_in_array(long long code, long long array[])
{
    int i;
    for(i=N-1;i>=0;i--)
    {
        array[i]=code%10;
        code=code/10;
    }
}

bool check_card_validation(long long array[], long long code)
{
    int i,sum;
    if(array[0]<4 || array[0]>7 || check_digits(code)!=N)
        return FALSE; /*check for number of digits*/
    else
    {
        for(i=0;i<N;i+=2)
        {
            array[i]*=2;
            if (array[i]>=10)
            array[i]=array[i]%10 + array[i]/10;
        }

        sum=0;
        for(i=0;i<N;i++)
            sum+=array[i];
        if ((sum%10==0)) return TRUE;
        return FALSE;
    }
}

long long GetLongLong(void)
{
    string line;
    long long value;
    char termch;

    while (TRUE) {
        line = GetLine();
        switch (sscanf(line, " %lld %c", &value, &termch)) {
          case 1:
            FreeBlock(line);
            return (value);
          case 2:
            printf("Unexpected character: '%c'\n", termch);
            break;
          default:
            printf("Please enter an integer\n");
            break;
        }
        FreeBlock(line);
        printf("Retry: ");
    }
}



