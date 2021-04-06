/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a16f5: �� ���������� (�� �� ����� ��� ����������� ��� �������������) ��������� ��� �����,
- �� ������� ��� ������ a �������� 50 �� �������� �������� ��� �� 0 ��� �� 9 ��������������� ��� ��������� rand() (a[i]=rand() % 10),
��� ����������� <stdlib.h> (��������� populate)
- �� ��������� ��� ������ a ���� ����� (��������� printArr),
- �� ���� ���� ������� ������ � ��� �� 0 ��� ��� �� 9 ��� ��� ������ - ��� ���������� �������,
- �� ����� ��� ��������� checkTable, � ����� �� ���������� ��� ������ ��� ���������� ��� ������� � ���� ������ a ��� ��� ������ ��� ������ ���� ������ ����������� � �������
- �� ��������� �� ������������ ��� ������, ���� �������� ��� ���������� ���������. � �������� ��� ������������� �� ������� ��� �� ��������� main() (������ ���������),
��� ��� ������ ��� ����������� � ������� � �������� ��� printArr */

#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"

#define W 50

void populate(int r, int a[r]);
void printArr(int r, int a[r]);
int checkTable(int r, int N, int a[r], int index[r]);

int main()
{
    int a[W],index[W];
    int N;

    populate(W,a);
    printArr(W,a);
    printf("\nDose arithmo apo to 0 ews to 9: ");
    N=GetInteger();
    printf("\no Arithmos %d emfanizetai %d fores.\nStis Theseis:\n",N,checkTable(W,N,a,index));
    printArr(checkTable(W,N,a,index),index);
    printf("\n");

    system("PAUSE");
    return 0;

}

void populate(int r, int a[r])
{
    int i;
    for(i=0;i<r;i++)
        a[i]=rand()%10;
}

void printArr(int r, int a[r])
{
    int i;
    for(i=0;i<r;i++)
        printf("%d  ",a[i]);
    printf("\n-------------");
}

int checkTable(int r, int N, int a[r], int index[r])
{
    int i,sum;

    sum=0;
    for(i=0;i<r;i++)
    {
        if ((a[i]==N))
        {index[sum]=i;
         sum++;}

    }
    return sum;
}


