/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 11:44:02 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 12:42:47 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

t_dlist	*copy_stack(t_dlist *a)
{
	t_dlist	*copy;
	int		*val;

	copy = NULL;
	while (a)
	{
		val = (int *)malloc(sizeof(int));
		*val = *(int *)a->content;
		ft_dlstadd_back(&copy, ft_dlstnew(val));
		a = a->next;
	}
	return (copy);
}

t_dlist	*ft_dlstmin(t_dlist *lst)
{
	t_dlist	*min;

	if (!lst)
		return (NULL);
	min = lst;
	while (lst)
	{
		if (*(int *)lst->content < *(int *)min->content)
			min = lst;
		lst = lst->next;
	}
	return (min);
}

int	get_pos(t_dlist *stack, t_dlist *node)
{
	int	pos;

	pos = 0;
	while (stack)
	{
		if (stack == node)
			return (pos);
		pos++;
		stack = stack->next;
	}
	return (pos);
}

int	get_cost(int len, int pos)
{
	if (pos <= len / 2)
		return (pos);
	return (len - pos);
}
