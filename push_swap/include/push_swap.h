/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:09 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 21:44:36 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include "dlst.h"

typedef struct s_move
{
	t_dlist	*node;
	t_dlist	*target;
	int		cost_a;
	int		cost_b;
	int		total;
	bool	rev_a;
	bool	rev_b;
}	t_move;

typedef enum e_op
{
	OP_PA,
	OP_PB,
	OP_SA,
	OP_SB,
	OP_SS,
	OP_RA,
	OP_RB,
	OP_RR,
	OP_RRA,
	OP_RRB,
	OP_RRR
}	t_op;

bool	ft_parse_args(int argc, char **argv, t_stack *stack);
bool	ft_isdup(t_dlist **dlst);

char	**ft_split(char const *s, char c);
int		ft_countwords(const char *s, char c);
void	free_split(char **split, int size);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int n);
bool	strict_atoi(const char *s, int *result);

void	push(t_dlist **to, t_dlist **from);
void	swap(t_dlist **stack);
void	rotate(t_dlist **stack);
void	reverse_rotate(t_dlist **stack);

void	add_instruction(t_dlist **lst, t_op op);
void	print_instructions(t_dlist *dlst);

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

void	sort_three(t_dlist **inst, t_stack *stack);
void	sort_five(t_dlist **inst, t_stack *stack);
void	turkish_sort(t_dlist **inst, t_stack *stack);

t_dlist	*ft_dlstmin(t_dlist *lst);
t_dlist	*copy_stack(t_dlist *a);
t_dlist	*ft_dlstmin(t_dlist *lst);
int		get_pos(t_dlist *stack, t_dlist *node);
int		get_cost(int len, int pos);
void	sort_array(int *arr, int size);
void	index_stack(t_dlist *a);
t_dlist	*find_target(t_dlist *a, int index);
void	fill_move(t_move *m, t_stack *s, t_dlist *n);
void	exec_rot(t_dlist **inst, t_stack *s, t_move m);

#endif
