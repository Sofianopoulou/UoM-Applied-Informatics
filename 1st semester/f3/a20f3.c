/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a20f3: ������ ��� ��������� ��� �� �������� ��� ����� ��� ������� ��������
(��������� ������� int ��� ��������� ��� �� ������) ��� �� ������� ��� ��������� ��� �� ���������� ������.
�� ��������� �� ��������� �� �������� ������� ����� �� ����� �� ������ � ������� -1. */

#include <stdio.h>
#include "simpio.h"

int main()
{
    int age, max, min;

    printf("Dwse ilikia:");
    age = GetInteger();
    max = age;
    min = age;

    while(age !=-1)
    {
    max = (age>max) ? age:max;
    min = (age<min) ? age:min;

    printf("Dwse ilikia:");
    age = GetInteger();
    }

    printf("H megalyteri ilikia einai %d\n", max);
    printf("H mikroteri ilikia einai %d", min);
    return 0;
}
