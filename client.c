/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduli>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 19:10:20 by lbarture          #+#    #+#             */
/*   Updated: 2022/02/15 21:23:48 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h>
#include<signal.h>
#include<unistd.h>
#include"libft/libft.h"

int main(int argc, char **argv)
{
	int pid;
	int ascii;
	int count;
	int q;
	int n;
	char c;

	q = 0;
	count = 0;
	n = 0;
	if(argc != 1)
	{
		while(q < 7)
		{
		pid = ft_atoi(argv[1]);
			while(argv[1][n])
			{		
				c = (argv[1][n]);
				n++;		
				if((c & (0x01<<q)) != 0)
				{
					//Se van guardando los bits que son 1 en la posición correspondiente en ascii.
					count++;
					ascii += 0x01<<q;
//					printf("Número de char: %d\n", pid);
					printf("bit = %d, ascii = %d\n", (0x01<<q), ascii);
					kill(pid, SIGUSR1);
					// ¿Cómo paso el ascii al server?
				}
				q++;
				printf("q = %d\n", q);
			}
		return(0);
		} 
	}
}
