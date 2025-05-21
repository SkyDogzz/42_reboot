/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:24:44 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 21:36:18 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus.h"

static bool	exec_inst(const char *line, t_stack *stack)
{
	if (ft_strncmp(line, "sa\n", 4) == 0)
		execsa(NULL, stack);
	else if (ft_strncmp(line, "sb\n", 4) == 0)
		execsb(NULL, stack);
	else if (ft_strncmp(line, "ss\n", 4) == 0)
		execss(NULL, stack);
	else if (ft_strncmp(line, "pa\n", 4) == 0)
		execpa(NULL, stack);
	else if (ft_strncmp(line, "pb\n", 4) == 0)
		execpb(NULL, stack);
	else if (ft_strncmp(line, "ra\n", 4) == 0)
		execra(NULL, stack);
	else if (ft_strncmp(line, "rb\n", 4) == 0)
		execrb(NULL, stack);
	else if (ft_strncmp(line, "rr\n", 4) == 0)
		execrr(NULL, stack);
	else if (ft_strncmp(line, "rra\n", 5) == 0)
		execrra(NULL, stack);
	else if (ft_strncmp(line, "rrb\n", 5) == 0)
		execrrb(NULL, stack);
	else if (ft_strncmp(line, "rrr\n", 5) == 0)
		execrrr(NULL, stack);
	else
		return (false);
	return (true);
}

bool	is_sorted(t_dlist *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (false);
		stack = stack->next;
	}
	return (true);
}

bool	is_empty(t_dlist *stack)
{
	if (ft_dlstsize(stack) == 0)
		return (true);
	return (false);
}

static void	inst(t_stack *stack)
{
	char	*line;

	line = get_next_line(0);
	if (ft_strncmp(line, "\n", 2) == 0)
	{
		free(line);
		get_next_line(-1);
		ft_dlstclear(&stack->a, free);
		ft_dlstclear(&stack->b, free);
		exit(EXIT_SUCCESS);
	}
	while (line)
	{
		if (ft_strlen(line) <= 1 || ft_strlen(line) >= 5)
			break ;
		if (!exec_inst(line, stack))
			exit_error(stack, line);
		free(line);
		line = get_next_line(0);
	}
	free(line);
	get_next_line(-1);
}

int	main(int argc, char **argv)
{
	t_stack	stack;

	stack.a = NULL;
	stack.b = NULL;
	if (!ft_parse_args(argc, argv, &stack) || ft_isdup(&stack.a))
		exit_error(&stack, NULL);
	inst(&stack);
	if (!is_sorted(stack.a) || !is_empty(stack.b))
		exit_ko(&stack);
	write(1, "OK\n", 3);
	ft_dlstclear(&stack.a, free);
	ft_dlstclear(&stack.b, free);
}
