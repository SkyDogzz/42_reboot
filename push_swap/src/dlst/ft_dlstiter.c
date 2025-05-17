/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstiter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:36:35 by skydogzz          #+#    #+#             */
/*   Updated: 2025/05/17 02:08:20 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

void	ft_dlstiter(t_dlist *dlst, void (*f)(void *))
{
	while (dlst)
	{
		f(dlst->content);
		dlst = dlst->next;
	}
}
