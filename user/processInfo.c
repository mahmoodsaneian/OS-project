#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"
#include "kernel/processInfo.h"

struct processInfo info;
int main(int argc){
    int i,j;
    int t = 0;
    for(i = 0;i<100000000;i++){
        for(j=0;j<100;j++){
            t++;
        }
    }
    processInfo((uint64)&info, argc);
    printf("cpu_burst_time: %d\n",info.cpu_burst_time);
    printf("turnaround_time: %d\n",info.turn_around_time);
    printf("waiting_time: %d\n",info.waiting_time);
    exit(0);
}