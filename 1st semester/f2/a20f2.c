/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a20f2: �� ������ ��� ��������� ��� ����� �� ��������� ���� ������ ������ (int)
��� �� 1 ��� �� 7 ��� ������� �� ������� ��� ���������� ���� ��� ���������. � ����� ���� ��� ��������� (1) ����� � ������� (Monday).
�� ������� ��� ������ �� ������������ ��� ������� (Monday, Tuesday, ... Sunday). �� ��������� �� ������� ������� ������ �� ����������� �� ������ "ERROR".*/

#include <stdio.h>
#include "simpio.h"

int main()
{
    int number;

    printf("Dwse enan arithmo apo to 1 eos to 7:");
    number = GetInteger();
    switch(number)
    {
    case 1:
        printf("The day is Monday \n", number);
        break;
    case 2:
        printf("The day is Tuesday \n", number);
        break;
    case 3:
        printf("The day is Wednesday \n", number);
        break;
    case 4:
        printf("The day is Thursday \n", number);
        break;
    case 5:
        printf("The day is Friday \n", number);
        break;
    case 6:
        printf("The day is Saturday \n", number);
        break;
    case 7:
        printf("The day is Sunday \n", number);
        break;
    default:
        printf("ERROR");
        break;
    }

      return 0;
}
