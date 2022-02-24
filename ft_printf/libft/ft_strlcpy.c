/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 18:03:12 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:10:27 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_strlcpy(char *dst, const	char *src, size_t dstsize)
{
	size_t	x;
	size_t	y;

	x = 0;
	y = 0;
	if (!src)
		return (0);
	while (src[x] != '\0')
		x++;
	if (dstsize != 0)
	{
		while (src[y] != '\0' && (dstsize - 1) > y)
		{
			dst[y] = src[y];
			y++;
		}
		dst[y] = '\0';
	}
	return (x);
}
