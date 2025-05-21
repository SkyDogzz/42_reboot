/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:58:14 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/21 11:42:47 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

int	ft_dlstsize(t_dlist *dlst)
{
	int	len;

	len = 0;
	while (dlst)
	{
		dlst = dlst->next;
		len++;
	}
	return (len);
}
