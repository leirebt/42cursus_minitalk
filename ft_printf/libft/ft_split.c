/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbarture <lbarture@student.42urduliz.com>  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 19:57:37 by lbarture          #+#    #+#             */
/*   Updated: 2021/09/07 18:18:48 by lbarture         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	start_string(char const *s, char c, int count)
{
	if (!count)
		count = 0;
	while (s[count])
	{
		if (s[count] != c && s[count])
		{
			count++;
			while (s[count] != c && s[count])
				count++;
			return (count);
		}
		count++;
	}
	return (count);
}

void	free_malloc(char	**p)
{
	size_t	count;

	count = 0;
	while (p[count])
	{
		free(p[count]);
		count++;
	}
	free (p);
}

char	*fill_string(char const *s, char c, int count)
{
	size_t	start;
	size_t	end;
	char	*ptr;

	ptr = NULL;
	if (!count)
		count = 0;
	while (s[count])
	{
		if (s[count] != c && s[count])
		{
			start = count;
			count++;
			while (s[count] != c && s[count])
				count++;
			end = count;
			ptr = ft_substr(s, start, (end - start));
			if (!ptr)
				return (NULL);
			return (ptr);
		}
		count++;
	}
	return ((char *)s);
}

int	count_words(char const *s, char c)
{
	int	count;
	int	words;

	count = 0;
	words = 0;
	while (s[count])
	{
		while (s[count] == c && s[count])
			count++;
		if (s[count] != c && s[count])
		{
			words++;
			while (s[count] != c && s[count])
				count++;
		}
	}
	return (words);
}

char	**ft_split(char const *s, char c)
{
	char	**p;
	int		words;
	int		count;
	int		start;

	start = 0;
	count = 0;
	if (!s)
		return (0);
	words = count_words (s, c);
	p = (char **) malloc ((words + 1) * sizeof (char *));
	if (!p)
		return (0);
	p[words] = NULL;
	while (words)
	{
		p[count] = fill_string(s, c, start);
		if (p[count] == NULL)
			free_malloc(p);
		start = start_string(s, c, start);
		count++;
		words--;
	}
	return (p);
}
