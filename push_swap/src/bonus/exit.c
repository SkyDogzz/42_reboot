/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:33:59 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 07:42:11 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/bonus.h"

void	exit_error(t_stack *stack, char *s)
{
	if (s)
		free(s);
	ft_dlstclear(&stack->a, free);
	ft_dlstclear(&stack->b, free);
	get_next_line(-1);
	write(2, "Error\n", 6);
	exit(EXIT_FAILURE);
}

void	exit_ko(t_stack *stack)
{
	ft_dlstclear(&stack->a, free);
	ft_dlstclear(&stack->b, free);
	write(2, "KO\n", 3);
	exit(EXIT_FAILURE);
}
