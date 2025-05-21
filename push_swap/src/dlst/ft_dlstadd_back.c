/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_back.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:07:32 by skydogzz          #+#    #+#             */
/*   Updated: 2025/05/21 11:45:33 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

t_dlist	*ft_dlstadd_back(t_dlist **dlst, t_dlist *ne)
{
	t_dlist	*head;
	t_dlist	*last;

	if (!dlst)
		return (NULL);
	if (*dlst == NULL)
	{
		*dlst = ne;
		return (*dlst);
	}
	head = *dlst;
	last = ft_dlstlast(head);
	last->next = ne;
	ne->prev = last;
	return (head);
}
