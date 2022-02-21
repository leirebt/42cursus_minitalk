#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include"ft_printf/ft_printf.h"

void print(int sig)
{
	static int ascii;
	static int q;
	
	if(!q)
	{
		q = 0;
		ascii = 0;
	}
	if(sig == SIGUSR1)
		ascii += 0x01<<q;
	q++;
	if(q == 8)
	{
		ft_printf("%c", (char)ascii);
		q = 0;
	}
}

int	main()
{
	struct sigaction sa;
	pid_t si_pid; //¿Cómo le pasa el PID?
	sa.sigaction = sig;
	printf("Número PID: %d\n", getpid());
	signal(SIGUSR1, &sa, NULL);
	signal(SIGUSR2, &sa, NULL);

	while(1)
	{
		sleep(1);
	}
	return(0);
}
