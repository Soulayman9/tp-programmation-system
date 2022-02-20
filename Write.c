#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <time.h>
#include <sys/stat.h>

int main(int argc, char *argv[]) {

    char *filename = argv[1];
    char *temp = argv[2];
    FILE *fp1, *fp2;
    char c;
    fp1 = fopen(filename, "a");
    fp2 = fopen(temp, "r");
    int i;


   	while (!feof(fp2)) {
   	c = fgetc(fp2);
        fputc(c, fp1);
    	}
    
   fclose(fp1);
   fclose(fp2);   

printf("Done!!!!!!!!!!!!!!!!!!!!!!!");
}
