#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <signal.h>
#include <sched.h>
#include <sys/wait.h>

#include "main.h"
int core_service_pid = 0;

void startService(int * service_pid, void (*service_job)() )
{
	int pid = fork();
	if(0 == pid)		// child process
	{
		int current_pid = getpid();
		struct sched_param m_sched_param;
		m_sched_param.sched_priority = 0;
		if(sched_setscheduler(current_pid, SCHED_OTHER,&m_sched_param))
			perror("sched_setscheduler");

		// run service
		*service_pid = current_pid;
		service_job();
		exit(0);
	}
	else if(pid > 0)	// parent process
		core_service_pid = pid;
	else			// failed
		core_service_pid = 0;
}
void stopService(int * service_pid)
{
	if(*service_pid > 0)
	{
		kill(*service_pid, 9);
		sched_yield();
		usleep(10);

		int s;
		waitpid(*service_pid, &s, WNOHANG);
		*service_pid = 0;
	}
}

int main(int argc, char **argv)
{
	if(argc < 2 || !strncmp(argv[1], "-h", 2) || !strncmp(argv[1], "--help", 6) )
	{
		printf( "Usage> %s --help\n", argv[0] );
		exit(0);
	}
	return 0;
}
