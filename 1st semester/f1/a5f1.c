/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a5f1:  �� ������ ��������� ��� �������� ��� ���� �������� (int), ��� ������ ���������� (long)
��� �� ������� (double) ��� ��������� ���� ������ ��� ��� �������� ���������� �� ��������� ��� ����������� �������� ��� (double),
�� ���� ��� ��������� (double) ��� ���� ��� ��� ������� ��� �������� (double). � ����������� ��� ����� �� ������� �� ����:
���. ��������= ���� * ������ ���������� ���������= ������� �������� * ������� ����������� ��������= ������� �������� + ���������*/

#include <stdio.h>
#include "simpio.h"

int main(){

    int WorkingHours;
    long HourlyWages;
    double HoldRate;
    double GrossEarnings;
    double HoldAmount;
    double NetEarnings;

    printf ("Dwse ton arithmo twn wrwn: ");
    WorkingHours = GetInteger();
    printf ("Dwse thn wriaia antimisthia: ");
    HourlyWages = GetLong();
    printf ("Dwse to pososto twn krathsewn: ");
    HoldRate = GetReal();

    NetEarnings = WorkingHours*HourlyWages;
    HoldAmount = NetEarnings*HoldRate;
    GrossEarnings = NetEarnings + HoldAmount;

    printf ("Oi akatharistes apodoxes einai %g\n", GrossEarnings);
    printf ("Oi krathseis einai %g\n", HoldAmount);
    printf ("Oi kathares apodoxes einai %g\n", NetEarnings);

      return 0;
}















