#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

int main(int argc, char *argv[]){
int sig, pid;
sig = atoi(argv[1]);
pid = atoi(argv[2]);
kill(pid, sig);
printf("--Done--\n");
return 0;
}
