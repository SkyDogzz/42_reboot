/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstclear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 16:10:24 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 07:37:25 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

void	ft_dlstclear(t_dlist **dlst, void (*del)(void *))
{
	t_dlist	*tmp;

	while (*dlst)
	{
		tmp = (*dlst)->next;
		if (del)
			del((*dlst)->content);
		free(*dlst);
		*dlst = tmp;
	}
}

