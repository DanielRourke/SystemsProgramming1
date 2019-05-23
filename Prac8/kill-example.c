/* synchro, example for kill */

#include <unistd.h>
#include <signal.h>
int ntimes=0;
main()
{
  int i;
  pid_t pid, ppid;
  void p_action(int), c_action(int);
  static struct sigaction pact, cact;

  /* set SIGUSR1 action for parent */
  pact.sa_handler = p_action;
  sigaction(SIGUSR1, &pact, NULL);
switch(pid=fork())
  {
      case -1:   /* error */
      perror("synchro");
      exit(1);
      case 0:
      cact.sa_handler = c_action; /* set action for child */
      sigaction(SIGUSR1, &cact, NULL);
      ppid=getppid(); /* get parent p_id */
      for (i=1; i<3; i++)
      {
        sleep(1);
        kill(ppid, SIGUSR1);
        pause();
      }
default:  /*parent */
      for (i=1;i<3;i++)
      {
        pause();
        sleep(1);
        kill(pid, SIGUSR1);
      }
  }
}

void p_action(int sig)
{
  printf("Parent caught signal #%d\n", ++ntimes);
}

void c_action(sig)
{
  printf("Child caught signal #%d\n", ++ntimes);
}