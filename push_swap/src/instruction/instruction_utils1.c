/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:46 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:28:47 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execpa(t_dlist **inst, t_stack *stack)
{
	push(&stack->a, &stack->b);
	add_instruction(inst, "pa");
}

void	execpb(t_dlist **inst, t_stack *stack)
{
	push(&stack->b, &stack->a);
	add_instruction(inst, "pb");
}

void	execsa(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	add_instruction(inst, "sa");
}

void	execsb(t_dlist **inst, t_stack *stack)
{
	swap(&stack->b);
	add_instruction(inst, "sb");
}

void	execss(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	add_instruction(inst, "ss");
}
