#include <stdio.h>


int main(int argc, char *argv[])
{
    // Path to old and new files
    char *oldpath = argv[1], *newpath = argv[2];
	if (rename(oldpath, newpath) == 0)
    {
    	printf("--File renamed successfully--\n");
        
    }
    else
    {
    	printf("--Unable to rename files. Please check files exist and you have permissions to modify files--\n");
    }
	return 0;
}
