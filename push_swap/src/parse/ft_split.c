/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 14:44:11 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:29:00 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

int	ft_countwords(const char *s, char c)
{
	int	count;
	int	in_word;

	count = 0;
	in_word = 0;
	while (*s)
	{
		if (*s != c && !in_word)
		{
			in_word = 1;
			count++;
		}
		else if (*s == c)
			in_word = 0;
		s++;
	}
	return (count);
}

void	free_split(char **split, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(split[i++]);
	}
	free(split);
}

static char	*get_next_word(const char **s, char c)
{
	int	len;

	while (**s && **s == c)
		(*s)++;
	len = 0;
	while ((*s)[len] && (*s)[len] != c)
		len++;
	return (ft_strndup(*s, len));
}

char	**ft_split(char const *s, char c)
{
	char	**split;
	int		words;
	int		i;

	if (!s)
		return (NULL);
	words = ft_countwords(s, c);
	split = (char **)malloc(sizeof(char *) * (words + 1));
	if (!split)
		return (NULL);
	i = 0;
	while (i < words)
	{
		split[i] = get_next_word(&s, c);
		if (!split[i])
		{
			free_split(split, i);
			return (NULL);
		}
		s += ft_strlen(split[i]);
		i++;
	}
	split[i] = NULL;
	return (split);
}
