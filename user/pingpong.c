#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int
main()
{
  int parent_fd[2], child_fd[2];
  pipe(parent_fd);
  pipe(child_fd);
  char buf[1];
  if (fork() == 0){
    close(parent_fd[1]);
    close(child_fd[0]);
    if (read(parent_fd[0], buf, 1)) {
      fprintf(1, "%d: received ping\n", getpid());
    }
    write(child_fd[1], "B", 1);
    close(child_fd[1]);
  } else {
    close(parent_fd[0]);
    close(child_fd[1]);
    write(parent_fd[1], "A", 1);
    if (read(child_fd[0], buf, 1)) {
      fprintf(1, "%d: received pong\n", getpid());
    }
    close(parent_fd[1]);
  }
  exit(0);
}
