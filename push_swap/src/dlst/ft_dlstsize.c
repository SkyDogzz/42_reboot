/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstsize.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/20 15:58:14 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:38:37 by tstephan         ###   ########.fr       */
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
