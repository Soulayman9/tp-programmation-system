#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

//int i=0;
int main(){

pid_t getpid(void);
pid_t getppid(void);

int id ;
id = fork() ;

    if ( id == 0 )
    {
    printf ( "\nChild : Hello I am the child process\n");
    printf ( "Child : My PID is:   %d\n", getpid());
    }
    else
    {
    printf ( "\nParent : Hello I am the parent process\n" ) ;
    printf ( "Parent : My PID is:   %d\n", getpid());
    } 
}
