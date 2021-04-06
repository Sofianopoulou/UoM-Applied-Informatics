/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a27f4: �� ������� ��������� ��� �� �������� ��� ������ ��� ��� ���� ���� �������� ������� ��������� ��� ������� ������� �� ��� �������������.
� ������� �� ������ �� ����� ��� �������� [0..2000] ��� �� ������� � ����������� ������� ��� �� ���������. � ������� ��� ��������� (������� ��� ����) �� �����������
����� �� ����� �� ������� �� ����� (����� ���������� ���������).

������� ���� ������� ��� ��������� ������� �� ���� ������ ������� ������� �� ��� ������ ���, �� ����:
������� ��������� ������� ��������
    1..300               5%
    301..500            10%
    501..1000           15%
    1001..2000          20%

����������� ������
��� ���� ������ �������� ������� ������, ���� ������� � ������� ����������� �� ������� ����.
������������, ��� ���� ������ �������:
� ���� ������ ���������� ��� ��� ���� ��� ���
� �������� ��� �� �������� �� ������ ��� 1000 ��� ��� 1500 ���� ������ ��� ���� 5 ���� ��� ������� ����� ��� ���������. (������ ��� ����� ��� ��������� ���� ��� �������).
�� �������� ������ ������������� ��� ��� ���� ��������_������ = ceil(������ ����/5)

��� ����������:

��� ��� ������ �� ������ 1200 ��� ���� 100�:
� � ������ ���� �� �����: 80�
� �� ���� ��� ��������: 20�
� �� ������: 17
��� ��� ������ �� ������ 100 ��� ���� 10�:
� � ������ ���� �� �����: 9.50� � �� ���� ��� ��������: 0.50�
� �� ������: 1
�� ��������� �� ��������� ���� ����� �� ��������:
� �� ������ ������ ��� �� �������� � ������� (���� ��� �������)
� �� �������� ���� ��������
� �� ������ ��� ������ */

#include <stdio.h>
#include <math.h>
#include "simpio.h"

int get_code();
int  product_points(int code, double price);
double discount_percentage(int code);

int main()
{
    int code, points;
    double price, finalPrice, discount, total, discountSum;

    total = discountSum = 0;
    points = 0;

    while((code = get_code()))
    {
        printf("Dwse thn timh: ");
        price = GetReal();
        discount = discount_percentage(code)*price;
        discountSum += discount;
        finalPrice = price - discount;
        total += finalPrice;
        points += product_points(code, finalPrice);
    }

    printf("------------------\n");
    printf("Teliko synolo: %.2f Euro\n", total);
    printf("Ekptwsh: %.2f Euro\n", discountSum);
    printf("Pontoi: %d\n", points);

    system("PAUSE");
    return 0;
}

int get_code()
{
    int code;
    while(TRUE)
    {
        printf("Dwse ton kwdiko: ");
        code = GetInteger();
        if (code>=0 && code <=2000)
            return code;
        printf("Lathos Kwdikos (0-2000)\n");
    }
}

double discount_percentage(int code)
{
    if (code<=300) return 0.05;
    else if(code<=500) return 0.10;
    else if(code<=1000) return 0.15;
    else return 0.20;
}

int  product_points(int code, double fPrice)
{
    int points = 1;
    if (code>=1000 && code<=1500)
        points += ceil(fPrice/5);
    return points;
}
