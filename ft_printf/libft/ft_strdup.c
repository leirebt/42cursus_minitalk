/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 12:38:55 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:08:48 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *s1)
{
	char	*p;
	size_t	strlen;
	int		c;

	c = 0;
	strlen = ft_strlen((char *)s1);
	p = (char *)malloc((strlen + 1) * sizeof(char));
	if (!p)
		return (NULL);
	else
	{
		while (s1[c])
		{
			p[c] = (char)s1[c];
			c++;
		}
		p[c] = '\0';
		return (p);
	}
}
