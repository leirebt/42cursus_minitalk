/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 18:34:59 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/08 18:46:17 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 1;
	if (lst)
	{
		while (lst -> next != NULL)
		{
			lst = lst -> next;
			count++;
		}
		return (count);
	}
	return (0);
}
