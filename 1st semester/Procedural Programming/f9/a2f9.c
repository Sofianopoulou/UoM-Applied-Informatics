/*Apostolia Maria Sofianopoulou AM: iis21118

Εκφώνηση άσκησης a2f9:
Δίνεται το αρχείο κειμένου ‘i2f9.dat’ των μαθητών ενός σχολείου που περιλαμβάνει τα εξής στοιχεία για κάθε μαθητή:
 ονοματεπώνυμο μαθητή, το οποίο δεν μπορεί να περιλαμβάνει περισσότερους από 30 χαρακτήρες
 αριθμός απουσιών (int)
 διάφορα στοιχεία μαθητή, τα οποία δεν μπορούν να ξεπερνάνε τους 68 χαρακτήρες Τα παραπάνω στοιχεία για κάθε μαθητή
χωρίζονται με κόμμα. Ζητείται να γίνει πρόγραμμα που να δημιουργεί αρχείο μαθητών με απουσίες άνω των 100.
Το πρόγραμμα θα ζητά τα ονόματα των αρχείων "εισόδου" (i2f9.dat) και "εξόδου" (o2f9.dat) από τον χρήστη. Από το αρχείο μαθητών ‘i2f9.dat’
θα δημιουργείται το αρχείο κειμένου ‘o2f9.dat’ που θα περιέχει το ονοματεπώνυμο (30 χαρακτήρες) και τον αριθμό απουσιών (int) κάθε μαθητή
που οι απουσίες του ξεπερνούν τις 100. Τέλος, θα περιέχει το πλήθος όλων των μαθητών του σχολείου καθώς και το πλήθος των μαθητών του σχολείου
που οι απουσίες τους ξεπερνούν τις 100. */

#include <stdio.h>
#include "genlib.h"
#include "simpio.h"
#include <string.h>

#define MAXS 100

typedef struct{
    char name[30];
    int apousies;
} studentT;

void readInput(FILE* infile, studentT students[], int *pApousies, int *pStudents);
void WriteOutput(FILE *outfile, int size, studentT students[], int total);

int main()
{
    FILE *infile;
    FILE *outfile;
    char inputfilename[30];
    char outfilename[30];
    studentT students[MAXS];
    int numStudents, numAp100;

    while(TRUE){
    printf("Dwste to onoma gia to arxeio eisodou: ");
    gets(inputfilename);
    infile = fopen(inputfilename, "r");
    if(infile != NULL){break;}
    printf("Cannot open input file %s. Try again \n", inputfilename);
    }

    printf("Dwste to onoma gia to arxeio eksodou: ");
    gets(outfilename);
    outfile = fopen(outfilename, "w");

    //computation
    readInput(infile, students, &numAp100, &numStudents);
    WriteOutput(outfile, numAp100, students, numStudents);
    //closing
    fclose(infile);
    fclose(outfile);

    return 0;
}

void readInput(FILE* infile, studentT students[], int *pApousies100, int *pStudents)
{
    char name[30];
    char comments[68];
    char termch;
    int apousies;
    int nscan;

    *pStudents=0;
    *pApousies100=0;

    while(TRUE){
        nscan = fscanf(infile,"%30[^,], %d, %68[^\n]%c", name, &apousies, comments, &termch);
        if(nscan == EOF) break;
        if(nscan != 4 || termch != '\n')
          {printf("Error in file.");
           exit(1);}
        (*pStudents)++;
        if(apousies>100)
        {
            strcpy(students[*pApousies100].name,name);
            students[*pApousies100].apousies=apousies;
            (*pApousies100)++;
        }
    }
}

void WriteOutput(FILE *outfile, int size, studentT students[], int total)
{
    int i;

    fprintf(outfile, "%-30s%-9s\n", "ONOMATEPWNYMO", "APOYSIES");
    for(i=1; i<=39; i++)
        fputc('-', outfile);
    fputc('\n', outfile);

    for(i=0; i<size; i++)
        fprintf(outfile, "%-30s%9d\n", students[i].name, students[i].apousies);

    for(i=0;i<=39;i++)
        fputc('-', outfile);
    fputc('\n', outfile);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO MATHITWN:", total);
    fprintf(outfile, "%-30s%9d\n", "SYNOLO APONTWN:", size);
}

