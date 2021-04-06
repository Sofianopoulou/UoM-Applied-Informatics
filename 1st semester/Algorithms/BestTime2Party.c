#include <stdio.h>
#include <string.h>
#include "simpio.h"
#include "genlib.h"

#define N 23

void Introduction();
void Read_Array(int r,int c1, int c2, string array1[r][c1], float array2[r][c2]);
void FindBestHour(int r, int c1, int c2, string array1[r][c1], float array2[r][c2]);
int find_max(int array[6]);

int main()
{
    string celebrity[N][1];
    float hours[N][2];

    Introduction();
    Read_Array(N,1,2,celebrity,hours);
    FindBestHour(N,1,2,celebrity,hours);

    system("PAUSE");
    return 0;
}

void Introduction()
{
    printf("\tHello Stathis!\n\n We're super excited that the heavy metal xMas Bazaar is finally here!\n");
    printf("As you know, you can only attend the Bazaar for only an hour.\nWe're here to make sure that in that hour");
    printf(" you'll have the chance\nto see the most celebrities and have the most fun.\nSo let's begin! Please, tell us:\n");
}

void Read_Array(int r, int c1, int c2, string array1[r][c1], float array2[r][c2])
{
    int i;
    for(i=0;i<r;i++)
    {
        printf("\nWho's the celebrity? ");
        array1[i][c1]=GetLine();
        printf("Arrival Time? ");
        array2[i][c1]=GetReal();
        printf("Departure Time? ");
        array2[i][c2]=GetReal();
    }
    printf("--------------------------\n");
    printf("The list of the bands who participate in the xMas Bazaar is the following: \n");
    for (i=0;i<r;i++) {printf("%-14s %.2f  %.2f\n",array1[i][c1],array2[i][c1],array2[i][c2]);}
    printf("\n");
}

void FindBestHour(int r, int c1, int c2, string array1[r][c1], float array2[r][c2])
{
    int i,j;
    int sum[6]={0,0,0,0,0,0};
    float time[6]={18.00, 19.00, 20.00, 21.00, 22.00, 23.00};

    for(i=0;i<r;i++)
    {
        for(j=0;j<6;j++)
       {
           if (time[j]>=array2[i][c1] && time[j]<array2[i][c2])
            sum[j]+=1;
       }
    }
    for(j=0;j<6;j++)
    printf("At %.2f there will be: %d band%s\n",time[j],sum[j],(sum[j]!=1) ? "s" : "");
    printf("--------------------------\n");

    for(j=0;j<6;j++)
    {
        if (sum[j]==find_max(sum))
          {
              printf("BestTime2Party is: %.2f \n\nThere will be:\n",time[j]);
              for(i=0;i<N;i++)
              {
                  if(time[j]>=array2[i][c1] && time[j]<array2[i][c2])
                    printf("%s \n",array1[i][c1]);
              }
              printf("\n");
          }
    }
    printf("\nHave fun Stathis! Can't wait to see the many selfies you'll post on your social media accounts! :) \n");
}

int find_max(int array[6])
{
    int max,j;
    max=array[0];
    for (j=0;j<6;j++)
    {
        if (array[j]>max)
            max=array[j];
    }
    return max;
}




