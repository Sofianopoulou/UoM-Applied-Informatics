/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a19f2: �� ������ ��������� ��� �� ���������� �� ���� ����������� (float) �� ���� ��� �������� CO2 (���������, int) �� ����:
0-120 ��./���. -> 0,9 ����/(��/���).
121-140 ��./��� -> 1,1 ����/(��/���).
> 140 ��./���. -> 1,7 ����/(��/���).
� ������ ��� ����� ���������.*/

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
