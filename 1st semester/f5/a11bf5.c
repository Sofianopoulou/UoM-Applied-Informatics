/*Apostolia Maria Sofianopoulou AM: iis21118

Η άσκηση a11f5 υλοποιημένη με συναρτήσεις. */

#include <stdio.h>
#include <math.h>
#include "genlib.h"
#include "simpio.h"

#define CTS 10
#define S 3

void ReadData(int r, int c, double temper[r][c]);
double CalculateAverage(int r, int c, double temper[r][c]);
void CalculateAvCity(int r, int c, double temper[r][c], double average[c]);
void CalculateMaxDeviation(double natavg, int r, int c, double temper[r][c], double mdeviation[r]);
void PrintResults(double natavg, int r, double average[r], double mdeviation[r]);

int main()
{
    double temper[CTS][S];
    double average[CTS], mdeviation[CTS];
    double natavg;

    ReadData(CTS,S,temper);
    natavg=CalculateAverage(CTS,S,temper);
    CalculateAvCity(CTS,S,temper,average);
    CalculateMaxDeviation(natavg,CTS,S,temper,mdeviation);
    PrintResults(natavg,CTS,average,mdeviation);

    system("PAUSE");
    return 0;
}

void ReadData(int r, int c, double temper[r][c])
{
    /*Read all Temperatures*/
    int i,j;
	for (i=0; i<r; i++)
		for (j=0; j<c; j++)
		  	{ printf("Temp of City %d During %d 8-hour period: ",i,j);
              temper[i][j] = GetReal();
              }
}

double CalculateAverage(int r, int c, double temper[r][c])
{
    /*Calculating The Average of all Cities&Temps*/
    int i,j;
    double natavg;
    natavg = 0;
    for (i=0; i<r; i++)
      for (j=0; j<c; j+=1)
         natavg += temper[i][j];
    natavg = natavg/(r*c);
    return natavg;
}

void CalculateAvCity(int r, int c, double temper[r][c], double average[c])
{
    /*Calculating Average temp on each City*/
    int i,j;
	for (i=0; i<r; i++)
    {
        average[i] = 0;
        for (j=0; j<c; j++)
        {
            average[i] += temper[i][j];
        }
        average[i] = average[i]/c;
    }
}

void CalculateMaxDeviation(double natavg, int r, int c, double temper[r][c], double mdeviation[r])
{
    /*Calculating Standard Deviation*/
    int i,j;
    double devnat[r][c];

    for (i=0; i<r; i++)
        for (j=0; j<c; j++)
            devnat[i][j] = fabs(natavg-temper[i][j]);

	/*Calculating max Deviation*/
    for (i=0; i<r; i++)
    {
        mdeviation[i] = devnat[i][0];
        for(j=1; j<c; j++)
            if (mdeviation[i]<devnat[i][j])
                mdeviation[i] = devnat[i][j];
    }
}

void PrintResults(double natavg, int r, double average[r], double mdeviation[r])
{
    /*Printing results*/
    int i;
    printf("%3.1f\n", natavg);
    for (i=0; i<r; i+=1)
		printf("City %d  %.1f  %.1f\n",i, average[i], mdeviation[i]);
}

