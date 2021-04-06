/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a1bf3: �� ������� ��������� ��� ���� ��� ��� ��� �������� �����������:
a. � ��������� ������� ����������� ��� ����������� �� ��� ���� ����� 80000. �� � �������
����� ��������� �� ����� 7%, �� ������ ��������� ��� �� ���������� �� ���� ������ � �������
��� ����������� �� ��������� ��� 160000. ���� �� ����� ���� �� ����������;
b. ���������� �� ��������� ��� �rithmo_�ytok (long) ����������, ��� ���������� �� ������ �����
Rythmos ��� ��������� ��� ������� ���� �rio (long), �������� �� ����� �� ������� � �������.

�� ����������� a ��� b �� ���������� �� ��� (long) ��� ��� ������ ��� ����������� (long) ���� �� ��������� �� ������� ����.
��� ��� ���������� ��� ������� ������� ����������� �� �������������� � �����:
������� ����������� = ceil(������� ����������� *(1+������ �������)) */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

int main(){

    long initial_cars;
    double rate;
    long limit;
    long cars;
    long years;

    printf("Dwse ton arxiko arithmo autokinhtwn:");
    initial_cars = GetLong();
    printf("Dwse ton ethsio rythmo ayxhshs:");
    rate = GetReal();
    printf("Dwse to orio:");
    limit = GetLong();

    years = 0;
    cars = initial_cars;
    while (cars <= limit)
    {
        cars = ceil(cars*(1+rate));
        years++;
    }

    printf("After %ld years number of Cars is %ld. \n", years, cars);
    //system("PAUSE");
    return 0;

}
