/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 16:51:03 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/02 17:41:40 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include"libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;
	char	num;

	num = (char)c;
	len = (ft_strlen ((char *)s));
	if (num == '\0')
		return ((char *)&s[len]);
	while (len > 0)
	{
		if (s[len] == num)
			return ((char *)&s[len]);
		else
			len--;
	}
	if (s[len] == num)
		return ((char *)s);
	return (0);
}
