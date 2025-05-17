/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   instruction.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:44 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:28:44 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static void	ft_putstrendl_fd(const char *s, const int fd)
{
	write(fd, s, ft_strlen(s));
	write(fd, "\n", 1);
}

void	add_instruction(t_dlist **dlst, const char *ins)
{
	t_dlist	*new;

	new = ft_dlstnew(ft_strdup(ins));
	ft_dlstadd_back(dlst, new);
}

static void	print(void *content)
{
	ft_putstrendl_fd(content, 1);
}

void	print_instructions(t_dlist *dlst)
{
	ft_dlstiter(dlst, print);
}
