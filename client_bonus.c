/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:10:20 by lbarture          #+#    #+#             */
/*   Updated: 2022/02/23 20:06:12 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<signal.h>
#include<unistd.h>
#include"ft_printf/libft/libft.h"
#include"ft_printf/ft_printf.h"

void response(int pid)
{
	(void)pid;
	ft_printf("Received signal!\n");
}

int signals(char c, int pid)
{
	static int	q;
	int	ascii;

	if(!q)
    {
        q = 0;
        ascii = 0;
    }
	ascii = 0;
	while(q < 8)
	{
		if((c & (0x01<<q)) != 0)
		{
			ascii += 0x01<<q;
        	if (kill(pid, SIGUSR1) < 0)
			{
				ft_printf("Sorry, the introduced PID is invalid. 🤥\n");
				return(0);
			}
		}
		else
		{
			if(kill(pid, SIGUSR2) < 0)
			{
				ft_printf("Sorry, the introduced PID is invalid. 🤥\n");
				return(0);
			}
		}
    q++;
    sleep(10);
    }    
	if(q == 8)
        q = 0;
	return(1);
}

int main(int argc, char **argv)
{
	int pid;
	int n;

	signal(SIGUSR1, &response);
	n = 0;
	if(argc == 3)
	{
		pid = ft_atoi(argv[1]);
		if(pid > 0)
		{
		while(argv[2][n])
		{
			if(signals(argv[2][n], pid) == 0)
				return(0);
			n++;
		}
		signals('\n', pid);
		return(0);
		} else
			ft_printf("Please, introduce a valid PID.\n");
	} else
		ft_printf("Please, introduce 3 arguments.\n");
}
