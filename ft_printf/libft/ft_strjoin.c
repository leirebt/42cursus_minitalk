/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:52:00 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/23 17:56:30 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	total_len;
	char	*p;

	if (!s1)
		return (0);
	total_len = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	p = (char *) malloc (total_len * sizeof (char));
	if (!p)
		return (0);
	ft_strlcpy(p, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat((char *)p, s2, total_len);
	return ((char *)p);
}
