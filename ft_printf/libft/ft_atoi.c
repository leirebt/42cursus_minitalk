/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 18:16:38 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 16:57:56 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_atoi(const char *str)
{
	int					sign;
	size_t				c;
	unsigned long int	str2;

	sign = 1;
	c = 0;
	str2 = 0;
	while ((str[c] >= '\t' && str[c] <= '\r') || str[c] == ' ')
		c++;
	if ((str[c] == '+' || str[c] == '-') && str[c] != '\0')
	{
		if (str[c] == '-')
			sign *= -1;
		c++;
	}
	while ((str[c] >= '0' && str[c] <= '9') && str[c] != '\0')
	{
		str2 = (str[c] - '0') + (str2 * 10);
		c++;
	}
	if (str2 > 9223372036854775807 && sign == -1)
		return (0);
	else if (str2 > 9223372036854775807 && sign == 1)
		return (-1);
	return (str2 * sign);
}
