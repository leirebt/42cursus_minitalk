/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 20:12:32 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/03 18:33:12 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	pos;
	size_t	count;

	pos = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[pos] && pos < len)
	{
		if (haystack[pos] == needle[0])
		{
			count = 1;
			while (needle[count] && haystack[pos + count] == needle[count]
				&& (pos + count) < len)
				count++;
			if (needle[count] == '\0')
				return ((char *)&haystack[pos]);
		}
		pos++;
	}
	return (0);
}
