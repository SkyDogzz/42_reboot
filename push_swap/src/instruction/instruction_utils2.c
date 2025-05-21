/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:49 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 11:54:57 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execra(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->a);
	add_instruction(inst, OP_RA);
}

void	execrb(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->b);
	add_instruction(inst, OP_RB);
}

void	execrr(t_dlist **inst, t_stack *stack)
{
	rotate(&stack->a);
	rotate(&stack->b);
	add_instruction(inst, OP_RR);
}

void	execrra(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->a);
	add_instruction(inst, OP_RRA);
}

void	execrrb(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->b);
	add_instruction(inst, OP_RRB);
}
