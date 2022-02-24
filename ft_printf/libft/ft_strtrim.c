/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 18:05:49 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/23 19:51:12 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	search_in_set(const char *set, char c)
{
	size_t	count;

	count = 0;
	while (set[count])
	{
		if (set[count] == c)
			return (1);
		count++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	c;

	start = 0;
	if (!s1 || !set)
		return (0);
	while (s1[start] && search_in_set(set, s1[start]))
		start++;
	end = ft_strlen((char *)s1);
	while (end > start && search_in_set(set, s1[end - 1]))
		end--;
	p = (char *) malloc ((end - start) + 1 * sizeof(char));
	if (!p)
		return (0);
	c = 0;
	while (start < end)
		p[c++] = s1[start++];
	p[c] = '\0';
	return (p);
}
