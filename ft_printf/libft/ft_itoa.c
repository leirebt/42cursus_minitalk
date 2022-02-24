/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/04 18:34:20 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/07 18:16:39 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	number_len(int n)
{
	size_t	len;

	len = 0;
	if (n < 0)
		len++;
	if (n == 0)
		return (1);
	while (n)
	{
		n = n / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	char	*str;
	size_t	len;
	size_t	c;
	long	n_long;

	c = 0;
	n_long = n;
	len = number_len(n);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str)
		return (0);
	if (n_long < 0)
	{
		n_long *= -1;
		c = 1;
	}
	str[len] = '\0';
	while (len--)
	{
		str[len] = (n_long % 10) + '0';
		n_long = n_long / 10;
	}
	if (c == 1)
		str[0] = '-';
	return (str);
}
