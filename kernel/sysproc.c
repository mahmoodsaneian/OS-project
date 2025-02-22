#include "types.h"
#include "riscv.h"
#include "defs.h"
#include "param.h"
#include "memlayout.h"
#include "spinlock.h"
#include "proc.h"


uint64
sys_exit(void)
{
  int n;
  argint(0, &n);
  exit(n);
  return 0;  // not reached
}

uint64
sys_getpid(void)
{
  return myproc()->pid;
}

uint64
sys_fork(void)
{
  return fork();
}

uint64
sys_wait(void)
{
  uint64 p;
  argaddr(0, &p);
  return wait(p);
}

uint64
sys_sbrk(void)
{
  uint64 addr;
  int n;

  argint(0, &n);
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

uint64
sys_sleep(void)
{
  int n;
  uint ticks0;

  argint(0, &n);
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(killed(myproc())){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

uint64
sys_kill(void)
{
  int pid;

  argint(0, &pid);
  return kill(pid);
}

// return how many clock tick interrupts have occurred
// since start.
uint64
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

uint64
sys_getProcTick(void){
  int pid;

  argint(0, &pid);
  return getProcTick(pid);
}

uint64
sys_sysinfo(void){
  uint64 p;
  argaddr(0, &p);
  return sysinfo((struct sysinfo *)p);
}

uint64
sys_changeScheduler(void){
  int type;
  //retrieve process id
  argint(0, &type);
  return changeScheduler(type);
}

uint64 sys_processInfo(void){
    uint64 info;
    int pid;
    argint(1,&pid);
    argaddr(0, &info);
    if(info<0)
        return -1;
    int result = processInfo(info,pid);
    return result;
}

uint64
sys_customWait(void)
{
  uint64 pid;
  argaddr(0, &pid); 
  uint64 processTime;
  argaddr(1, &processTime); 
  return customWait(pid,processTime);
} 
