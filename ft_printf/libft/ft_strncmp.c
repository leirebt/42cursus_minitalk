/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/11 18:36:37 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/30 17:11:51 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	count;

	count = 0;
	if (n > 0)
	{
		while (count < n - 1 && s1[count] != '\0' && s2[count] != '\0'
			&& s1[count] == s2[count])
		{
			count++;
		}
		return ((unsigned char)s1[count] - (unsigned char)s2[count]);
	}
	return (0);
}
