/* Stock Market Analysis
 */

#include <stdio.h>

float find_max_tab(int size, float tab[]);
int fill_int_tab(float max, int size, float tab[], float tab_int[]);
void separator(int num);
void print_tab(int size, float tab[]);
void print_tab_with_max(float max, int size, float tab[]);
float access_cds(float cds, int risk);
void high_low(int *low , int *high , int row ,int r , int c , float table[r][c]);;

int main(){
   float stock_prices[10] = {34.5, 22.4, 77.8, 22.1, 10.0, 11.25, 12, 13, 16, 20.5 };
   float deriv_prices[5] = {30.5, 21.4, 89.8, 20.1, 10.0};
   float cds_prices[11] = {38.5, 33.4, 67.8, 12.1, 16.0, 10.25, 11, 23, 36, 10.1 ,30.4};
   int risk[11] = {90,10,20,30,50,60,30,30,30,10,10};

   float deriv_day_data[5][10] = {
                {30.5,25,22,32.3,30.5,32.6,38.9,40,22,30.5},
                {22.5,21.4,14,40.3,22.5,12.6,38.9,40,39,21.4},
                {30.5,25,22,89.8,34.5,89.8,38.9,40,30,89.8},
                {20.2,35,20.1,12.3,20.1,32.6,38.9,40,22,20.1},
                {45.5,10.0,22,10.0,14.5,23.6,48.9,8,10.0,10.0}
   };


   float interesting_stock[10];
   int ni_stock;
   float interesting_cds[11];
   int ni_cds;

   int i;
   float max_stock, max_deriv, max_cds;


   /* Calculating Max Values */
     max_stock = find_max_tab(10,stock_prices);
     max_deriv = find_max_tab(5,deriv_prices);
     max_cds = find_max_tab(11,cds_prices);

   /* Finding Interesting Values */
    ni_stock = fill_int_tab(max_stock, 10, stock_prices, interesting_stock);
    ni_cds = fill_int_tab(max_cds, 11, cds_prices, interesting_cds);

   /* Printing */

   printf("Stock Prices.\n");
   separator(30);
   print_tab_with_max(max_stock, 10, stock_prices);
   printf("Interesting Stock Prices:");
   print_tab(ni_stock, interesting_stock);
   separator(10);

   /* Derivatives */
   printf("Derivative Prices.\n");
   separator(30);
   print_tab_with_max(max_deriv, 5, deriv_prices);
   separator(10);

   /* Cds Prices */

   printf("CDS Prices.\n");
   separator(30);
   print_tab_with_max(max_cds, 11, cds_prices);
   printf("Interesting CDS Prices:");
   print_tab(ni_cds, interesting_cds);
   separator(10);

   //2
   printf("CDS assessment\n");
   for(i=0;i<11;i++)
    printf("CDS assessment: cds %4.2f Risk %d Value %4.2f\n", cds_prices[i], risk[i], access_cds(cds_prices[i],risk[i]));
   separator(30);
   printf("Derivative Low High\n");
   int low, high;
   for(i=0;i<5;i++)
   {
    high_low(&high,&low,i,5,10,deriv_day_data);
    printf("Derivative %d, high %d / low %d values.\n", i, high, low);
   }

   return 0;
}

float find_max_tab(int size, float tab[])
{
    int i;
    float max;
    max = tab[0];
    for(i=0;i<size;i++)
      if (tab[i]>max) {max = tab[i];}
    return max;
}

int fill_int_tab(float max, int size, float tab[], float tab_int[])
{
    int i, num;
    num=0;
    for(i=0;i<size;i++)
        if (tab[i] > max/2)
        {tab_int[num++] = tab[i];}
    return num;
}

void separator(int num)
{
    int i;
    for(i=0;i<num;i++) printf("-");
    printf("\n");
}
void print_tab(int size, float tab[])
{
    int i;
    for(i=0;i<size;i++)
        printf("[%4.2f] ",tab[i]);
    printf("\n");
}

void print_tab_with_max(float max, int size, float tab[])
{
    int i;
    printf("Max Price:: %4.2f \n",max);
    for(i=0;i<size;i++)
      printf("%s(%3.2f) ",(max == tab[i] ? "-Max-" : ""),tab[i]);
   printf("\n");
}

float access_cds(float cds, int risk)
{
    if(cds < 20 && risk < 50) return 20;
    if (cds >= 20 && risk < 80) return 10+(cds*risk)/100;
    return 100+(cds*risk)/100;
}

void high_low(int *low , int *high , int row ,int r , int c , float table[r][c])
{
    int i;
    *high=0;
    *low=0;
    for (i=0;i<c;i++)
    {
        if (table[row][i]<table[row][c-1]) (*high)++;
        if (table[row][i]>table[row][c-1]) (*low)++;
    }
}


