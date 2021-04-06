#include <stdio.h>
#include <stdlib.h>
#include "simpio.h"

#define N 13

void FindDislikes(int size, int array[][size], int sum[]);
void FindMax(int size, int array[], int *max, int *pointer);
bool Dislikes(int size, int array[][size]);
void fill_table_with_random_numbers(int row, int list[10], int vektor[7], int array[1000][7]);
void sort_the_table(int row, int array[1000][7]);
void find_the_possible_invitations(int size, int max_guests, int table[1000][7], int array[][size], int guests[15][max_guests]);
bool found(int max_guests, int row, int table[1000][7], int guests[15][max_guests]);

int main()
{
    string names[N]={"Nikos", "Lydia", "Giannis", "Akis", "Manos", "Eva", "Elenh", "Petros", "Dimitris", "Maria", "Alexandros", "Anna", "Zwh"};
    int sum[N];
    int list[10]={0,1,2,3,4,5,8,9,10,11}, vektor[7], table[1000][7], row;  //afhnw thn Elenh(6), th Zwh(12) kai ton Petro(7) eksw apo th lista, giati h Zwh tha einai panta kai h Elenh pote, ara kai o Petros panta
    int i,j,k,max,pointer,max_guests;
    int array_duplicate[N][N];
    int array[N][N]={
        {0, 1,  0,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0},
        {1,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0,	0},
        {1,	0,	1,	0,	1,	0,	0,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	1,	0,	1,	1,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	1,	0,	0,	0,	0,  0,	0,	0,	0},
        {0,	0,	0,	0,	1,	0,	0,	1,	1,	1,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	0,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	1,	0,	0,	1,	0,	0,	0},
        {0,	0,	0,	0,	0,	0,	1,	0,	1,	0,	1,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	1,	0,	1,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,  0,	1,	0,	0},
        {0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0,	0}};

        // Finding max number of guests
    for(i=0;i<N;i++)
        for(j=0;j<N;j++)
            array_duplicate[i][j]=array[i][j];

    max_guests=N;
    while(Dislikes(N,array_duplicate)==TRUE)
        {
            FindDislikes(N,array_duplicate,sum);
            FindMax(N,sum,&max,&pointer);
            for(i=0;i<N;i++)
                {array_duplicate[i][pointer]=0;
                array_duplicate[pointer][i]=0;}
            max_guests--;
        }
    printf("-------------------BALL MASKE ORGANIZATION-------------------\n\n");
    printf("Max number of guests is: %d\n",max_guests);

        // Checking Possibilities
    for(row=0;row<1000;row++)
        fill_table_with_random_numbers(row, list, vektor, table);

    for(row=0;row<1000;row++)
        sort_the_table(row, table);

        // Checking if each random row of 7 is possible to come to the party without turning it into a war zone
    int guests[15][max_guests];

    for(i=0;i<15;i++)
        {for(j=0;j<max_guests;j++)
        guests[i][j]=0;}

    find_the_possible_invitations(N, max_guests, table, array,guests);

        // Printing possible guests
    printf("Stathis can pick one out of 15 lists of friends to invite at the Ball Maske: \n\n");

    k=1;
    for(i=0;i<15;i++)
        {printf("%d| ", k);
        k++;
        for(j=0;j<max_guests;j++)
            {printf("%s ", names[guests[i][j]]);}
        printf("\n");}

    printf("\n\nHave fun! :) \n");

    system("PAUSE");
    return 0;
}

    // Finding max number of guests
void FindDislikes(int size, int array[][size], int sum[])
{
    int i,j;
    for(i=0;i<size;i++)
        sum[i]=0;

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            if(array[i][j]==1)
                sum[i]++;
}

void FindMax(int size, int array[], int *max, int *pointer)
{
    int i;
    *max=array[0];
    *pointer=0;
    for(i=1;i<size;i++)
    {
        if(array[i]>*max)
        {
            *max=array[i];
            *pointer=i;
        }
    }
}

bool Dislikes(int size, int array[][size])
{
    int i,j;

    for(i=0;i<size;i++)
        for(j=0;j<size;j++)
            if(array[i][j]==1)
                return TRUE;
            return FALSE;
}

    // Checking Possibilities
void fill_table_with_random_numbers(int row, int list[10], int vektor[7], int array[1000][7])
{
    int i;

    for (i = 0; i < 10; i++) {
    int j = i + rand() % (10- i);
    int temp = list[i];
    list[i] = list[j];
    list[j] = temp;}

    vektor[0]=12; //dhladh h Zwh
    vektor[1]=7; //dhladh o Petros
    for (i = 2; i < 7; i++)
        {vektor[i] = list[i];}

    for(i=0;i<7;i++)
        array[row][i]=vektor[i];
}

void sort_the_table(int row, int array[1000][7])
{
    int i,j,a;
    for(i=0;i<7;i++)
    {
        for(j=i+1;j<7;++j)
        {if(array[row][i] > array[row][j])
        {a = array[row][i];
        array[row][i]=array[row][j];
        array[row][j]=a;}}
    }
}

    // Checking if each random row of 7 is possible to come to the ball maske without turning it into a war zone
void find_the_possible_invitations(int size, int max_guests, int table[1000][7], int array[][size], int guests[15][max_guests])
{
    int i,k,row;
    k=0;

    for(row=0;row<1000;row++)
    {if(found(max_guests,row,table,guests)==FALSE && array[table[row][0]][table[row][1]]==0 && array[table[row][0]][table[row][2]]==0 && array[table[row][0]][table[row][3]]==0 && array[table[row][0]][table[row][4]]==0 && array[table[row][0]][table[row][5]]==0 && array[table[row][0]][table[row][6]]==0 && array[table[row][0]][table[row][7]]==0 && array[table[row][1]][table[row][2]]==0 && array[table[row][1]][table[row][3]]==0 && array[table[row][1]][table[row][4]]==0 && array[table[row][1]][table[row][5]]==0 && array[table[row][1]][table[row][6]]==0 && array[table[row][1]][table[row][7]]==0 && array[table[row][2]][table[row][3]]==0  && array[table[row][2]][table[row][4]]==0&& array[table[row][2]][table[row][5]]==0 && array[table[row][2]][table[row][6]]==0 && array[table[row][2]][table[row][7]]==0 && array[table[row][3]][table[row][4]]==0 && array[table[row][3]][table[row][5]]==0 && array[table[row][3]][table[row][6]]==0 && array[table[row][3]][table[row][7]]==0  && array[table[row][4]][table[row][5]]==0 && array[table[row][4]][table[row][6]]==0 && array[table[row][4]][table[row][7]]==0 && array[table[row][5]][table[row][6]]==0 && array[table[row][5]][table[row][7]]==0 && array[table[row][6]][table[row][7]]==0)
        {for(i=0;i<max_guests;i++)
            {guests[k][i]=table[row][i];}
            k++;}}
}
    // Checking if combination has already been found
bool found(int max_guests, int row, int table[1000][7], int guests[15][max_guests])
{
    int i,j;
    int c[15];

    for(i=0;i<15;i++)
        c[i]=0;

    for(i=0;i<15;i++)
        for(j=0;j<max_guests;j++)
            if(table[row][j]==guests[i][j])
                c[i]++;

    for(i=0;i<15;i++)
        if(c[i]==max_guests) return TRUE;
    return FALSE;
}



















