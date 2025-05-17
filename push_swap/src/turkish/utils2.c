/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:43:21 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 12:55:35 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	sort_array(int *arr, int size)
{
	int	tmp;
	int	i;
	int	j;

	i = -1;
	while (++i < size - 1)
	{
		j = -1;
		while (++j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

static int	*fill_array_from_stack(t_dlist *a, int size)
{
	int		*arr;
	int		i;

	arr = (int *)malloc(sizeof(int) * size);
	if (!arr)
		return (NULL);
	i = 0;
	while (i < size && a)
	{
		arr[i] = *(int *)a->content;
		a = a->next;
		i++;
	}
	return (arr);
}

void	index_stack(t_dlist *a)
{
	int		size;
	int		*arr;
	t_dlist	*tmp;
	int		i;
	int		val;

	size = ft_dlstsize(a);
	arr = fill_array_from_stack(a, size);
	if (!arr)
		return ;
	sort_array(arr, size);
	tmp = a;
	while (tmp)
	{
		val = *(int *)tmp->content;
		i = -1;
		while (++i < size)
			if (arr[i] == val)
				break ;
		*(int *)tmp->content = i;
		tmp = tmp->next;
	}
	free(arr);
}

t_dlist	*find_target(t_dlist *a, int index)
{
	t_dlist	*best;
	t_dlist	*tmp;
	int		val;

	best = NULL;
	tmp = a;
	while (tmp)
	{
		val = *(int *)tmp->content;
		if (val > index && (!best || val < *(int *)best->content))
			best = tmp;
		tmp = tmp->next;
	}
	if (!best)
		best = ft_dlstmin(a);
	return (best);
}

void	fill_move(t_move *m, t_stack *s, t_dlist *n)
{
	int	pa;
	int	pb;
	int	la;
	int	lb;

	m->node = n;
	m->target = find_target(s->a, *(int *)n->content);
	pa = get_pos(s->a, m->target);
	pb = get_pos(s->b, n);
	la = ft_dlstsize(s->a);
	lb = ft_dlstsize(s->b);
	m->rev_a = pa > la / 2;
	m->rev_b = pb > lb / 2;
	m->cost_a = get_cost(la, pa);
	m->cost_b = get_cost(lb, pb);
	m->total = m->cost_a + m->cost_b;
}
