/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/21 11:33:19 by lbarture          #+#    #+#             */
/*   Updated: 2021/08/21 12:33:51 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_calloc(size_t	num, size_t	size)
{
	void	*p;

	p = malloc (num * size);
	if (!p)
		return (NULL);
	else
	{
		ft_bzero (p, num * size);
		return (p);
	}
}
