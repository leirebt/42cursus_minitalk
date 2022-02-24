/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/17 17:23:16 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:05:37 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t	n)
{
	size_t	c;

	c = 0;
	while (n > 0)
	{
		if (((unsigned char *)s1)[c] == ((unsigned char *)s2)[c])
		{
			c++;
			n--;
		}
		else
			return (((unsigned char *)s1)[c] - ((unsigned char *)s2)[c]);
	}
	return (0);
}
