/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a20f5: �� ������ ��� ��������� �� ����� �� �������� 5 ��������� ��� �� ���� ���������� �� ���� ������.
��� ��������, �� ��������� �� ����������� �� �������� ��� ������ ��� ���� ����� ��� �� ������� ��� ������ ���� �����.
��� ����������, �� �� �������� ��� ������ �����: 1, -9, 5, 3, 4 � ������� ���� ��� ���������� �� �����: 4, 1, -9, 5, 3.*/

#include <stdio.h>
#include "simpio.h"

#define N 5

int main()
{
    int array[N];
    int switched_array[N];
    int i;

    for(i=0;i<N;i++)
    {
        printf("Enter Number: ");
        array[i]=GetInteger();
    }

    for(i=0;i<N-1;i++)
      { switched_array[i+1]=array[i]; }
    switched_array[0]=array[N-1];

    for(i=0;i<N;i++)
        printf("%d ",switched_array[i]);

    return 0;
}
