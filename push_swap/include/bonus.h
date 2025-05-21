/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 07:24:37 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 07:48:19 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include "get_next_line.h"
# include "dlst.h"

bool	ft_parse_args(int argc, char **argv, t_stack *stack);
bool	ft_isdup(t_dlist **dlst);

int		ft_strncmp(const char *s1, const char *s2, size_t n);

void	execpa(t_dlist **inst, t_stack *stack);
void	execpb(t_dlist **inst, t_stack *stack);
void	execsa(t_dlist **inst, t_stack *stack);
void	execsb(t_dlist **inst, t_stack *stack);
void	execss(t_dlist **inst, t_stack *stack);
void	execra(t_dlist **inst, t_stack *stack);
void	execrb(t_dlist **inst, t_stack *stack);
void	execrr(t_dlist **inst, t_stack *stack);
void	execrra(t_dlist **inst, t_stack *stack);
void	execrrb(t_dlist **inst, t_stack *stack);
void	execrrr(t_dlist **inst, t_stack *stack);

void	exit_error(t_stack *stack, char *s);
void	exit_ko(t_stack *stack);

#endif
