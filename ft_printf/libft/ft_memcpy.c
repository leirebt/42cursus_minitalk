/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/15 13:28:44 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:06:36 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include <string.h>
#include<stdio.h>

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	counter;

	counter = 0;
	if (dst || src)
	{
		while (n > 0)
		{
			((char *)dst)[counter] = ((char *)src)[counter];
			n--;
			counter++;
		}
		return (dst);
	}
	return (0);
}
