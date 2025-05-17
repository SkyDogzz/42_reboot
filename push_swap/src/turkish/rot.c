/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rot.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 12:57:45 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 12:57:45 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	exec_rot_together(t_dlist **inst, t_stack *s, t_move *m)
{
	while (m->rev_a && m->rev_b && m->cost_a && m->cost_b)
	{
		execrrr(inst, s);
		m->cost_a--;
		m->cost_b--;
	}
	while (!m->rev_a && !m->rev_b && m->cost_a && m->cost_b)
	{
		execrr(inst, s);
		m->cost_a--;
		m->cost_b--;
	}
}

static void	exec_rot_individual(t_dlist **inst, t_stack *s, t_move *m)
{
	while (m->cost_a--)
	{
		if (m->rev_a)
			execrra(inst, s);
		else
			execra(inst, s);
	}
	while (m->cost_b--)
	{
		if (m->rev_b)
			execrrb(inst, s);
		else
			execrb(inst, s);
	}
}

void	exec_rot(t_dlist **inst, t_stack *s, t_move m)
{
	exec_rot_together(inst, s, &m);
	exec_rot_individual(inst, s, &m);
	execpa(inst, s);
}
