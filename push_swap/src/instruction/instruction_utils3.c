/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction_utils3.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:49 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 11:54:17 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

void	execrrr(t_dlist **inst, t_stack *stack)
{
	reverse_rotate(&stack->a);
	reverse_rotate(&stack->b);
	add_instruction(inst, OP_RRR);
}
