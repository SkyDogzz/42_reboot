/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:29:02 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 11:46:04 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	populate(char **words, t_dlist **dlst)
{
	int		i;
	int		result;
	t_dlist	*new;

	i = 0;
	while (words[i])
	{
		if (!strict_atoi(words[i], &result))
			return (false);
		new = ft_dlstnew(result);
		ft_dlstadd_back(dlst, new);
		i++;
	}
	return (true);
}

bool	ft_parse_args(int argc, char **argv, t_stack *stack)
{
	char	**split;
	int		i;

	if (argc == 1)
		return (false);
	i = 1;
	while (i < argc)
	{
		split = ft_split(argv[i], ' ');
		if (!split)
			return (false);
		if (!populate(split, &stack->a))
		{
			free_split(split, ft_countwords(argv[i], ' '));
			return (false);
		}
		free_split(split, ft_countwords(argv[i], ' '));
		i++;
	}
	if (!stack->a)
		return (false);
	return (true);
}

static bool	ft_dlst_search(t_dlist **dlst, t_dlist *search)
{
	t_dlist	*act;

	act = *dlst;
	while (act)
	{
		if (act != search && (act->value == search->value))
			return (true);
		act = act->next;
	}
	return (false);
}

bool	ft_isdup(t_dlist **dlst)
{
	t_dlist	*act;

	act = *dlst;
	while (act)
	{
		if (ft_dlst_search(dlst, act))
			return (true);
		act = act->next;
	}
	return (false);
}
