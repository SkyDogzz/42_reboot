/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:32 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 08:45:14 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_move	find_best_move(t_stack *s)
{
	t_move	best;
	t_move	current;
	t_dlist	*tmp;

	tmp = s->b;
	fill_move(&best, s, tmp);
	tmp = tmp->next;
	while (tmp)
	{
		fill_move(&current, s, tmp);
		if (current.total < best.total)
			best = current;
		tmp = tmp->next;
	}
	return (best);
}

void	final_rotate(t_dlist **inst, t_stack *s)
{
	t_dlist	*min;
	int		pos;
	int		len;

	min = ft_dlstmin(s->a);
	pos = get_pos(s->a, min);
	len = ft_dlstsize(s->a);
	if (pos <= len / 2)
		while (pos--)
			execra(inst, s);
	else
		while (pos++ < len)
			execrra(inst, s);
}

void	biggest_part(t_dlist **inst, t_stack *s)
{
	int		idx;
	int		i;
	int		chunk;

	i = 0;
	chunk = 100;
	while (ft_dlstsize(s->a) > 3)
	{
		idx = *(int *)s->a->content;
		if (idx <= i)
		{
			execpb(inst, s);
			execrb(inst, s);
			i++;
		}
		else if (idx <= i + chunk)
		{
			execpb(inst, s);
			i++;
		}
		else
			execra(inst, s);
	}
}

void	turkish_sort(t_dlist **inst, t_stack *s)
{
	t_move	best;

	index_stack(s->a);
	biggest_part(inst, s);
	sort_three(inst, s);
	while (s->b)
	{
		best = find_best_move(s);
		exec_rot(inst, s, best);
	}
	final_rotate(inst, s);
}
