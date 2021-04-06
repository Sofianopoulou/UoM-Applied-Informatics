/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a19f2: Να γραφεί πρόγραμμα που να υπολογίζει τα τέλη κυκλοφορίας (float) με βάση τις εκπομπές CO2 (γραμμάρια, int) ως εξής:
0-120 γρ./χλμ. -> 0,9 ευρώ/(γρ/χλμ).
121-140 γρ./χλμ -> 1,1 ευρώ/(γρ/χλμ).
> 140 γρ./χλμ. -> 1,7 ευρώ/(γρ/χλμ).
Η χρέωση ΔΕΝ είναι κλιμακωτή.*/

#include <stdio.h>
#include "simpio.h"

int main()
{
    int CO2;
    float Poso;

    printf("Dwse gram CO2/Khm:");
    CO2 = GetInteger();

    if (CO2>0 && CO2<=120)
       Poso = CO2*0.9;
    else if (CO2>121 && CO2<=140)
       Poso = CO2*1.1;
    else
       Poso = CO2*1.7;

    printf("To poso pliromis einai: %g \n", Poso);

 return 0;
}
