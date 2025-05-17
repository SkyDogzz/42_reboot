/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dlst.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:28 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:40:03 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DLST_H
# define DLST_H

# include <stdlib.h>

typedef struct s_dlist	t_dlist;
typedef struct s_dlist
{
	void			*content;
	struct s_dlist	*prev;
	struct s_dlist	*next;
}					t_dlist;

t_dlist		*ft_dlstnew(void *content);
t_dlist		*ft_dlstadd_front(t_dlist **dlst, t_dlist *ne);
t_dlist		*ft_dlstadd_back(t_dlist **dlst, t_dlist *ne);
int			ft_dlstsize(t_dlist *dlst);
int			ft_dlstsize_full(t_dlist *dlst);
t_dlist		*ft_dlstfirst(t_dlist *dlst);
t_dlist		*ft_dlstlast(t_dlist *dlst);
void		ft_dlstiter(t_dlist *dlst, void (*f)(void *));
t_dlist		*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *));
void		ft_dlstdelone(t_dlist *dlst, void (*del)(void *));
void		ft_dlstclear(t_dlist **dlst, void (*del)(void *));

#endif
