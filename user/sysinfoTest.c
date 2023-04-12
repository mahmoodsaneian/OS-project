#include "kernel/types.h"
#include "user/user.h"

struct sysinfo{
  long uptime;
  unsigned long totalram;
  unsigned long freeram;
  unsigned short procs;
};


int 
main(void){
    struct sysinfo p;
    int success = sysinfo(&p);
    printf("uptime = %d\ntotlaram = %d\nfreeram = %d\nprocs = %d", p.uptime, p.totalram, p.freeram, p.procs);
    exit(success);
}