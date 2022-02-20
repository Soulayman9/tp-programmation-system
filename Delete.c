#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[]) {
   int ret;
   FILE *fp;
   
   char *path = argv[1];
  
   ret = remove(path);
   if(ret == 0) {
   	printf("--File deleted successfully--\n");
   } else {
	printf("--Error: unable to delete the file--\n");   

   }
   return(0);
}
