/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a14f1:  �� ������ ��������� ��� �� ���������� ��� �� ��������� �����
�������� ���������� ���������� ��� ������� � ����� ����� ��������� ���. � �������� ���
���������� ��� �� ������ ����������� ��� ���������� ����������, BMR, ������������ �� ����:
BMR = 655 + (9.6 X ����� �� ����) + (1.8 X ���� �� cm) - (4.7 X ������ �� ������).*/

#include <stdio.h>
#include "simpio.h"

int main(){

    double Weight;
    int Height;
    int Age;
    double BMR;

    printf ("Dwse varos se kila: ");
    Weight = GetReal();
    printf ("Dwse upsos se cm: ");
    Height = GetInteger();
    printf ("Dwse ilikia se xronia: ");
    Age = GetInteger();

    BMR = 655 + (9.6*Weight) + (1.8*Height) - (4.7*Age);
    printf ("To BMR einai: %g", BMR);

      return 0;
}
