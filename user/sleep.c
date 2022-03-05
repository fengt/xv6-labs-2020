#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int 
main(int argc, char *argv[])
{
  int n;
  if(argc < 2)
  {
    fprintf(2, "Usage: sleep n\n");
    exit(1);
  }
  n = atoi(argv[1]);
  sleep(n);
  fprintf(1, "Done sleeping for %d seconds\n", n);
  exit(0);
}
