#include <signal.h>
#include <stdio.h>
#include <unistd.h>

void function(int sig)
{
	printf("La señal es %d\n", sig);
}

int	main()
{
	printf("Número PID: %d\n", getpid());
	signal(SIGUSR1, &function);
	while(1)
	{
		sleep(1);
	}
	return(0);
}
