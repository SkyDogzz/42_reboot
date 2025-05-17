/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstadd_front.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:12:10 by skydogzz          #+#    #+#             */
/*   Updated: 2025/05/17 02:08:06 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

t_dlist	*ft_dlstadd_front(t_dlist **dlst, t_dlist *ne)
{
	if (!dlst)
		return (NULL);
	if (*dlst)
	{
		ne->next = *dlst;
		(*dlst)->prev = ne;
	}
	*dlst = ne;
	return (ne);
}
