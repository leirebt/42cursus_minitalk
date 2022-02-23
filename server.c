/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/21 19:21:57 by lbarture          #+#    #+#             */
/*   Updated: 2022/02/23 20:49:15 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <stdio.h>
#include <unistd.h>
#include"ft_printf/ft_printf.h"

void	print(int sig)
{
	static int	ascii;
	static int	q;

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
}

int	main(void)
{
	printf("Número PID: %d\n", getpid());
	signal(SIGUSR1, &print);
	signal(SIGUSR2, &print);
	while (1)
	{
		sleep(1);
	}
	return (0);
}
