/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:10:20 by lbarture          #+#    #+#             */
/*   Updated: 2022/02/16 21:19:49 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"ft_printf/libft/libft.h"

void signals(char c, int pid)
{
	int	q;
	int	ascii;

	q = 0;
	ascii = 0;
	while(q < 8)
	{
		if((c & (0x01<<q)) != 0)
		{
		//Se van guardando los bits que son 1 en la posición correspondiente en ascii.
			ascii += 0x01<<q;
        	printf("bit = %d, ascii = %d\n", (0x01<<q), ascii);
        	kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
    printf("q = %d\n", q);
    q++;
    usleep(10000);
    }
    printf("La letra es = %c\n",(char)ascii);
}

int main(int argc, char **argv)
{
	int pid;
	int n;

	n = 0;
	if(argc != 1)
	{
		pid = ft_atoi(argv[1]);
		if(pid > 0)
		{
		while(argv[2][n])
		{
			signals(argv[2][n], pid);
			n++;
		}
		signals('\n', pid);
		return(0);
		} 
	}
}
