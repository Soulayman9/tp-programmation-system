#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>

void exec1();
void exec2();

int pid;
int pipe1[2];

int main() {


  if (pipe(pipe1) == -1) {
    perror("bad pipe");
    exit(1);
  }

// cat /etc/passwd | grep root

  // fork (cat /etc/passwd)
  if ((pid = fork()) == -1) {
    perror("bad fork1");
    exit(1);
  } else if (pid == 0) {
    // stdin --> cat --> pipe1
    exec1();
  }
  
  // fork (grep root)
  if ((pid = fork()) == -1) {
    perror("bad fork2");
    exit(1);
  } else if (pid == 0) {
    // pipe1 --> grep --> pipe2
    exec2();
  }
  // parent

  // close unused fds
  close(pipe1[0]);
  close(pipe1[1]);

return 0;
  }


void exec1() {
  // input from stdin (already done)
  // output to pipe1
  dup2(pipe1[1], 1);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  // exec
  execlp("cat", "cat", "/etc/passwd", NULL);
  // exec didn't work, exit
  perror("bad exec cat /etc/passwd");
  _exit(1);
}

void exec2() {
  // input from pipe1
  dup2(pipe1[0], 0);
  // close fds
  close(pipe1[0]);
  close(pipe1[1]);
  // exec
  execlp("grep", "grep", "root", NULL);
  // exec didn't work, exit
  perror("bad exec grep 500");
  _exit(1);
}
