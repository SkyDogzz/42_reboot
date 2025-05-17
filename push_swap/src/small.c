/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:27:03 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 11:27:03 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_dlist **inst, t_stack *stack)
{
	int	a;
	int	b;
	int	c;

	a = *(int *)stack->a->content;
	b = *(int *)stack->a->next->content;
	c = *(int *)stack->a->next->next->content;
	if (a > b && b < c && a < c)
		execsa(inst, stack);
	else if (a > b && b > c)
	{
		execsa(inst, stack);
		execrra(inst, stack);
	}
	else if (a > b && b < c && a > c)
		execra(inst, stack);
	else if (a < b && b > c && a < c)
	{
		execsa(inst, stack);
		execra(inst, stack);
	}
	else if (a < b && b > c && a > c)
		execrra(inst, stack);
}

static t_dlist	*find_min(t_dlist *stack)
{
	t_dlist	*min;

	min = stack;
	while (stack)
	{
		if (*(int *)stack->content < *(int *)min->content)
			min = stack;
		stack = stack->next;
	}
	return (min);
}

int	get_index(t_dlist *stack, t_dlist *node)
{
	int	i;

	i = 0;
	while (stack)
	{
		if (stack == node)
			return (i);
		stack = stack->next;
		i++;
	}
	return (-1);
}

void	sort_five(t_dlist **inst, t_stack *stack)
{
	t_dlist	*min;

	while (ft_dlstsize(stack->a) > 3)
	{
		min = find_min(stack->a);
		while (stack->a != min)
		{
			if (get_index(stack->a, min) <= ft_dlstsize(stack->a) / 2)
				execra(inst, stack);
			else
				execrra(inst, stack);
		}
		execpb(inst, stack);
	}
	sort_three(inst, stack);
	execpa(inst, stack);
	execpa(inst, stack);
}
