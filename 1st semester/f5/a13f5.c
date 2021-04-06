/*Apostolia Maria Sofianopoulou AM: iis21118

�������� ������� a13f5: �� ������ ��������� �� �����:
(�) �� ���� ��� ��� ������ ��� �������� ��������� �������� R (�������) ��� C (������) ��� �� 1 ����� ��� �� 10. �������� �� ��������� �� �������� ��� � ������� �� �������
������� ������� ������� �� �� ����������� ����. ��� ���������� �������. � �������� �� ������� ��� ��� ��������� main.
(�) �� "�������" �� �������� R x C ���� ����������� ������ � �������� (��������� 10x10) �� �������� ��������� ��� 0 ��� ��� 99 (rand() % 100),
���� ������ ���� ���������� populate_data. ������ �� ��������� �� ������������ ����� ��� ������ �, ����� ��� ������� R ��� C, ��� �������� � �������.
(�) �� ����� ��� ��������� print_array ��� �� ������� �� R x C �������� ��� ������ �.
(�) �� ����� ��� ���������� change_array, � ����� ��� ���� ������ ���
������ � �� ����� ��� �������� ����� �������� ��� �������� ��� ������� ��� �� ���� (������ ��� ����� ���� ���� ������ �� ����, ���� ����� ��������� ������ ������ �� ������ ��� �� �� �������).
(�) �����, �� ������������ ��� ���� �� �������� ��� "����������" ������ ���� �������. ���� �� ����������� ��� �� ���������� �� ������� C99 ��� �������
2 ����������. ������� ���� �������� ��� ���������� ��� �����������. ����� ���� � �������� ��� ������, ��� ���� ���� ����� ��� ������ ���� ��������������. �� ������ �� �������� ������������ �����������. */

#include <stdio.h>
#include "simpio.h"

#define N 10

void populate_data(int R, int C, int array[N][N]);
void print_array(int R, int C, int array[N][N]);
void change_array(int R, int C, int array[N][N]);

int main()
{
    int R,C;
    int array[N][N];

    printf("Dwse ton arithmo twn grammwn: ");
    R=GetInteger();
    printf("Dwse ton arithmo twn sthlwn: ");
    C=GetInteger();

    populate_data(R,C,array);
    print_array(R, C, array);
    change_array(R,C,array);
}

void populate_data(int R, int C, int array[N][N])
{
    int i,j;
    for(i=0;i<R;i++)
        for(j=0;j<C;j++)
    {
        array[i][j] = rand()%100;
    }
}

void print_array(int R, int C, int array[N][N])
{
    int i,j;
    printf("ARXIKOS PINAKAS\n");
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {printf("%2d ", array[i][j]);}
        printf("\n");
    }
}

void change_array(int R, int C, int array[N][N])
{
    int i,j,k,max;
    int max_number[R];
    int pointer[R];

    for(i=0;i<R;i++)
    {
        max=0;
        for(j=0;j<C;j++)
        {
            if (array[i][j]>max)
            {
                max=array[i][j];
                max_number[i]=max;
                pointer[i]=j;
            }
        }
    }

    for(i=0;i<R;i++)
        for(k=0;k<pointer[i];k++)
        array[i][k]=max_number[i];

    printf("ALLAGMENOS PINAKAS\n");
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {printf("%2d ", array[i][j]);}
        printf("\n");
    }
}



