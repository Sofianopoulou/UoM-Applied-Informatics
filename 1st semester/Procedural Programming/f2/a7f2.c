/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a7f2: �� ������ ��� ��������� C ��� ��� ���������� ��� ��� �������� ��� ������������ ������� ���� ����������� �� ����:
�� ��������� �� �������� ��� ������ ������ (long) ��� �����������. �� � ������� ������� ����� ����������� � ���� ��� 1000, ���� �� ���������
�� �������� ��� ������ ����� ��� ����������� (double) ��� �� ���������� ��� ����������� ������ (double) ��� ���������� ��� ������ ����� ��� 52.
�� � ������� ����� ���������� ��� 1000, ���� �� ��������� �� �������� ��� ���� ������������ �������� (int) ��� �����������, ��� ������ ��� ��� (double)
��� ��� �������� �� ���������� ��� ����������� ������. �� � ����������� ������� ����� ��� ��� 40 ����, ���� ��� ��� ���� ���� ��� 40 ���� � ������ ���� ���������� 50%.*/

#include <stdio.h>
#include "simpio.h"

int main()
{
    long Code;
    double Salary, Wage, Weekly_amount;
    int Hours;

    printf("Dwse ton kwdiko:");
    Code = GetLong();

    if (Code >= 1000)
    {
         printf("Dwse ton ethsio mistho:");
         Salary = GetReal();
         Weekly_amount = Salary/52.0;
    }
    else
    {
         printf("Dwse tis wres ebdomadiaias ergasias:");
         Hours = GetInteger();
         printf("Dwse thn amoibh ana wra:");
         Wage = GetReal();
           if (Hours <= 40)
               {Weekly_amount = Hours*Wage;}
           else
               {Weekly_amount = 40*Wage + (Hours-40)*Wage*1.5;}
    }

     printf("H ebdomadiaia amoibh einai: %g\n", Weekly_amount);

     return 0;
}
