#include "kernel/types.h"
#include "user/user.h"
#include "kernel/param.h"
#include "kernel/syscall.h"

int
main(int argc, char *argv[])
{
  int i;
  char *nargv[MAXARG];

  if(argc < 3){
    fprintf(2, "Usage: %s mask command [args]\n", argv[0]);
    exit(1);
  }

  if (trace(atoi(argv[1])) < 0) {
    fprintf(2, "%s: trace failed\n", argv[0]);
    exit(1);
  }

  for(i = 2; i < argc && i < MAXARG; i++){
    nargv[i-2] = argv[i];
  }
  nargv[i-2] = 0;

  exec(nargv[0], nargv);

  fprintf(2, "%s: exec %s failed\n", argv[0], nargv[0]);
  exit(1);
}