/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a4f1:  ���� ������� ������� �� ���� ��������� ����������� ����� purchaseAmount �
��� �� ������� saleAmount �. �� �� ���� saleAmount ��������� ��� ��� ������ ���� purchaseAmount
��� �� ������� ������� rate ��� ������� ��� ��� ������� ����� purchaseAmount, �� ����� ���������
��� �� ���������� ��� �� ���������: �) �� ������ ��� ������� profit (double), �) �� ����������
���� saleAmount (double). �� �������� ������� �� ����� �� �����: purchaseAmount (��������� ����� long)
rate (��������� ����� int, ��� �� ������� ������� ����� 10% ���� �������������� 10) */

#include <stdio.h>
#include "simpio.h"

int main(){

    long purchaseAmount;
    int rate;
    double salesAmount;
    double profit;

    printf("Dwse thn katharh axia: ");
    purchaseAmount = GetLong();
    printf("Dwse to pososto kerdous:");
    rate = GetInteger();


    profit = purchaseAmount * ((double) rate / 100.0);
    salesAmount = purchaseAmount + profit;


    printf("To kerdos einai %g\n", profit);
    printf("To synoliko poso einai %g", salesAmount);

      return 0;
}
