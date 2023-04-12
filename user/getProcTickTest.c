#include "kernel/types.h"
#include "user/user.h"

int
main(void){
    sleep(10);
    int ticks = getProcTick(getpid());
    printf("%d\n", ticks);
    exit(0);
}

