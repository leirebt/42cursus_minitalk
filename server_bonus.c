/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 18:21:23 by lbarture          #+#    #+#             */
/*   Updated: 2022/02/23 20:53:08 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include"ft_printf/ft_printf.h"

void	print(int sig, siginfo_t *info, void *x)
{
	static int	ascii;
	static int	q;

	x = NULL;
	if (!q)
	{
		q = 0;
		ascii = 0;
	}
	if (sig == SIGUSR1)
		ascii += 0x01 << q;
	q++;
	if (q == 8)
	{
		ft_printf("%c", (char)ascii);
		q = 0;
	}
	usleep(5000);
	kill(info->si_pid, SIGUSR1);
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_sigaction = print;
	ft_printf("Número PID: %d\n", getpid());
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = 0;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
