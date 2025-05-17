/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstdelone.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:22:05 by skydogzz          #+#    #+#             */
/*   Updated: 2025/05/17 02:10:18 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

void	ft_dlstdelone(t_dlist *dlst, void (*del)(void *))
{
	if (dlst)
	{
		del(dlst->content);
		if (dlst->next)
			dlst->next->prev = NULL;
		free(dlst);
	}
}
