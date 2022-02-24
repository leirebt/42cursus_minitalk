/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 13:19:43 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/03 19:29:47 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

size_t	ft_total(unsigned int start, size_t len, size_t s_len)
{
	size_t	total;

	total = 0;
	if (start < s_len)
		total = start - s_len;
	if (total > len)
		total = len;
	if (s_len < len)
		total = s_len;
	return (total);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	s_len;
	size_t	total;

	if (!s)
		return (0);
	total = 0;
	s_len = ft_strlen((char *)s);
	total = ft_total(start, len, s_len);
	if (start >= ft_strlen(s))
	{
		p = malloc(1);
		p[0] = '\0';
		return (p);
	}
	p = (char *)malloc(sizeof(char) * (total + 1));
	if (p)
	{
		ft_strlcpy (p, &s[start], total + 1);
		return (p);
	}
	else
		return (NULL);
}
