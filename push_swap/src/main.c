/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:15:57 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 11:28:55 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

bool	is_sorted(t_dlist *stack)
{
	while (stack && stack->next)
	{
		if (*(int *)stack->content > *(int *)stack->next->content)
			return (false);
		stack = stack->next;
	}
	return (true);
}

void	execute_sort(t_dlist **inst, t_stack *stack)
{
	if (ft_dlstsize(stack->a) == 2)
	{
		if (*(int *)stack->a->content > *(int *)stack->a->next->content)
			execsa(inst, stack);
	}
	else if (ft_dlstsize(stack->a) == 3)
		sort_three(inst, stack);
	else if (ft_dlstsize(stack->a) <= 5)
		sort_five(inst, stack);
	else
		turkish_sort(inst, stack);
}

int	main(int argc, char **argv)
{
	t_stack	stack;
	t_dlist	*inst;

	inst = NULL;
	stack.a = NULL;
	stack.b = NULL;
	if (!ft_parse_args(argc, argv, &stack) || ft_isdup(&stack.a))
		write(2, "Error\n", 6);
	else if (!is_sorted(stack.a))
		execute_sort(&inst, &stack);
	print_instructions(inst);
	ft_dlstclear(&inst, free);
	ft_dlstclear(&stack.a, free);
	ft_dlstclear(&stack.b, free);
	return (0);
}
