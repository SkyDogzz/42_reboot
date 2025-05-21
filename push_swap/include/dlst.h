/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:28 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 21:41:44 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <stdlib.h>

typedef struct s_dlist	t_dlist;
typedef struct s_dlist
{
	int				value;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

typedef struct s_stack
{
	t_dlist	*a;
	t_dlist	*b;
}	t_stack;

t_dlist		*ft_dlstnew(int value);
t_dlist		*ft_dlstadd_back(t_dlist **dlst, t_dlist *ne);
int			ft_dlstsize(t_dlist *dlst);
t_dlist		*ft_dlstlast(t_dlist *dlst);
void		ft_dlstclear(t_dlist **dlst, void (*del)(void *));

#endif
