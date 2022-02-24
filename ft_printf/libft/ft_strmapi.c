/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/03 19:34:23 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/04 18:09:08 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	count;
	char	*p;

	count = 0;
	if (s && f)
	{
		p = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
		if (!p)
			return (0);
		while (s[count])
		{
			p[count] = f(count, (s[count]));
			count++;
		}
		p[count] = '\0';
		return (p);
	}
	return (0);
}
