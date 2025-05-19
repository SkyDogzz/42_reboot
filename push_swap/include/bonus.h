#ifndef BONUS_H
# define BONUS_H

# include <unistd.h>
# include <stdbool.h>
# include "dlst.h"

bool	ft_parse_args(int argc, char **argv, t_stack *stack);
bool	ft_isdup(t_dlist **dlst);

#endif
