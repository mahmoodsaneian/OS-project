#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"



int main(void)
{
    changeScheduler(1);
    int pid_rr, i, j;
    struct processInfo waitinfo_rr[32];
    for(i=0;i<32;i++){
        pid_rr = fork();
        if (pid_rr == 0)
        {
            int arr1[100000000];
            int arr2[100000000];
            long result = 0;
            for(j=0;j<100000000;j++){
                arr1[j] = 3;
            }
            for(j=0;j<100000000;j++){
                arr2[j] = 4;
            }
            for(j=0;j<100000000;j++){
                result+=arr1[j];
            }
            for(j=0;j<100000000;j++){
                result+=arr2[j];
            }
            break;
        }
    }
    if (pid_rr!=0)
    {
        int cbt_rr = 0;
        int tat_rr = 0;
        int wt_rr = 0;
        int exitStatus = 0;
        for (i = 0; i < 32; i++)
        {
            customWait(&exitStatus, &waitinfo_rr[i]);
            cbt_rr += waitinfo_rr[i].cpu_burst_time;
            tat_rr += waitinfo_rr[i].turn_around_time;
            wt_rr  += waitinfo_rr[i].waiting_time;
        }
        printf("Round Robin:\n");
        printf("cpu burst time = %d\n", (long) cbt_rr/32);
        printf("turanaround time = %d\n",(long) tat_rr/32);
        printf("waiting time = %d\n",(long) wt_rr/32);
        printf("-------------------------------------------\n");
    }
    if (pid_rr == 0)
    {
        return 0;
    }

    changeScheduler(0);
    struct processInfo waitinfo_fcfc[32];
    int pid_fcfs;
    for(i=0;i<32;i++){
        pid_fcfs = fork();
        if (pid_fcfs == 0)
        {
            int arr1[100000000];
            int arr2[100000000];
            long result = 0;
            for(j=0;j<100000000;j++){
                arr1[j] = 3;
            }
            for(j=0;j<100000000;j++){
                arr2[j] = 4;
            }
            for(j=0;j<100000000;j++){
                result+=arr1[j];
            }
            for(j=0;j<100000000;j++){
                result+=arr2[j];
            }
            break;
        }
    }
    if (pid_fcfs!=0)
    {
        int cbt_fcfs = 0;
        int tat_fcfs = 0;
        int wt_fcfs = 0;
        int exitStatus = 0;
        for (i = 0; i < 32; i++)
        {
            customWait(&exitStatus, &waitinfo_fcfc[i]);
            cbt_fcfs += waitinfo_fcfc[i].cpu_burst_time;
            tat_fcfs += waitinfo_fcfc[i].turn_around_time;
            wt_fcfs  += waitinfo_fcfc[i].waiting_time;
        }
        printf("First Come First Serve:\n");
        printf("cpu burst time = %d\n", (long) cbt_fcfs/32);
        printf("turanaround time = %d\n",(long) tat_fcfs/32);
        printf("waiting time = %d\n",(long) wt_fcfs/32);
        printf("-------------------------------------------\n");
    }   
    exit(0);
}