#include <stdio.h>

int main(int argc, char *argv[]){
  FILE *fp;
  char *path = argv[1];
  fp = fopen(path, "w");
  fclose(fp);
  printf("Done");
  return 0;
} 
