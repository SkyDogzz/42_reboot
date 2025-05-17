#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdio.h>
# include <stdbool.h>
# include <limits.h>
# include <unistd.h>
# include "dlst.h"

typedef struct s_stack {
	t_dlist *a;
	t_dlist *b;
}	t_stack;

bool	ft_parse_args(int argc, char **argv, t_stack *stack);
bool	ft_isdup(t_dlist **dlst);

// utils

char	**ft_split(char const *s, char c);
int	ft_countwords(const char *s, char c);
void	free_split(char **split, int size);

size_t	ft_strlen(const char *s);
char	*ft_strdup(const char *s);
char	*ft_strndup(const char *s, int n);
bool	strict_atoi(const char *s, int *result);

void	push(t_dlist **to, t_dlist **from);
void	swap(t_dlist **stack);
void	rotate(t_dlist **stack);
void	reverse_rotate(t_dlist **stack);

void	add_instruction(t_dlist **dlst, const char *ins);
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

#endif
