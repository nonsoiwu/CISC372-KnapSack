#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "time.h"
using namespace std;

int main(int argc, char const *argv[])
{
    if(argc < 2){
        return 1;
    }

    int v;
    int c = atoi(argv[1]);
    int val = 10;
    char *filename;

    if(c == 0){
        perror("Invalid expression or 0");
        return 1;
    }

    filename = (char*)malloc((strlen("./sample.txt")+strlen(argv[1])+1)*sizeof(char));
    sprintf(filename, "./sample%s.txt", argv[1]);
    FILE *f = fopen(filename, "w");
    srand (time(NULL));
    fprintf(f, "%d\n", c);
    
    //Get Weights
    for (size_t i = 0; i < c; i++)
    {
        v = rand() % val;
        fprintf(f, "%d\n", v);
    }

    //Get Values
    for (size_t i = 0; i < c; i++)
    {
        v = rand() % 10;
        fprintf(f, "%d\n", v);
    }

    fprintf(f, "%d\n", (int)((c*val)/2) );
    fclose(f);
    free(filename);
    return 0;

}