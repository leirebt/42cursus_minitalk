/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/09 17:27:30 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:09:41 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	y;
	size_t	x;
	size_t	count;

	x = 0;
	y = ft_strlen(dst);
	while (src[x] != '\0')
		x++;
	if (y < dstsize && dstsize != 0)
	{
		dstsize = dstsize - y - 1;
		count = y + x;
		x = 0;
		while (src[x] != '\0' && dstsize != 0)
		{
			dst[y++] = src[x++];
			dstsize--;
		}
		dst[y] = '\0';
		return (count);
	}
	else
		return (dstsize + x);
}
