/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/16 20:35:18 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:04:41 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *s, int c, size_t	n)
{
	size_t	count;

	count = 0;
	while (n--)
	{
		if (((unsigned char *)s)[count] == (unsigned char)c)
			return ((unsigned char *)&s[count]);
		else
			count++;
	}
	return (0);
}
