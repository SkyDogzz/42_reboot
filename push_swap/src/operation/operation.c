/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:55 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:43:37 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	push(t_dlist **to, t_dlist **from)
{
	t_dlist	*node;

	if (!from || !*from)
		return ;
	node = *from;
	*from = node->next;
	if (*from)
		(*from)->prev = NULL;
	node->next = *to;
	if (*to)
		(*to)->prev = node;
	node->prev = NULL;
	*to = node;
}

void	swap(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	if (second->next)
		second->next->prev = first;
	second->prev = NULL;
	second->next = first;
	first->prev = second;
	*stack = second;
}

void	rotate(t_dlist **stack)
{
	t_dlist	*first;
	t_dlist	*last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	last = ft_dlstlast(*stack);
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	reverse_rotate(t_dlist **stack)
{
	t_dlist	*last;
	t_dlist	*second_last;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	last = ft_dlstlast(*stack);
	second_last = last->prev;
	second_last->next = NULL;
	last->prev = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	*stack = last;
}
