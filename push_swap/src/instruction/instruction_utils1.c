/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:46 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 12:05:08 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execpa(t_dlist **inst, t_stack *stack)
{
	push(&stack->a, &stack->b);
	add_instruction(inst, OP_PA);
}

void	execpb(t_dlist **inst, t_stack *stack)
{
	push(&stack->b, &stack->a);
	add_instruction(inst, OP_PB);
}

void	execsa(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	add_instruction(inst, OP_SA);
}

void	execsb(t_dlist **inst, t_stack *stack)
{
	swap(&stack->b);
	add_instruction(inst, OP_SB);
}

void	execss(t_dlist **inst, t_stack *stack)
{
	swap(&stack->a);
	swap(&stack->b);
	add_instruction(inst, OP_SS);
}
