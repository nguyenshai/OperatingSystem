#include "kernel/types.h"
#include "kernel/riscv.h"
#include "kernel/sysinfo.h"
#include "user/user.h"

void
testmem()
{
  struct sysinfo info;
  if (sysinfo(&info) < 0) {
    printf("sysinfo failed\n");
    exit(1);
  }
  printf("Free memory: %ld bytes\n", info.freemem);
  printf("Processes: %ld\n", info.nproc);
  printf("Open files: %ld\n", info.nopenfiles);
}

int
main(int argc, char *argv[])
{
  printf("sysinfotest: start\n");
  testmem();
  printf("sysinfotest: done\n");
  exit(0);
}