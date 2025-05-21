/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:44 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 12:03:57 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static const char	*g_op_str[] = {
	"pa", "pb", "sa", "sb", "ss",
	"ra", "rb", "rr", "rra", "rrb", "rrr"
};

void	add_instruction(t_dlist **lst, t_op op)
{
	t_dlist	*new;

	new = ft_dlstnew((int)op);
	if (!new)
		return ;
	ft_dlstadd_back(lst, new);
}

void	print_instructions(t_dlist *lst)
{
	while (lst)
	{
		write(1, g_op_str[lst->value], ft_strlen(g_op_str[lst->value]));
		write(1, "\n", 1);
		lst = lst->next;
	}
}
