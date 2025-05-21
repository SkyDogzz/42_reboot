/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dlstmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: skydogzz <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 23:38:00 by skydogzz          #+#    #+#             */
/*   Updated: 2025/05/21 11:48:02 by skydogzz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/dlst.h"

/*static t_dlist	*create_and_add_elem(t_dlist **new_dlst, void *content,*/
/*	void (*del)(void *))*/
/*{*/
/*	t_dlist	*new_elem;*/
/**/
/*	new_elem = ft_dlstnew(content);*/
/*	if (!new_elem)*/
/*	{*/
/*		del(content);*/
/*		ft_dlstclear(new_dlst, del);*/
/*		return (NULL);*/
/*	}*/
/*	ft_dlstadd_back(new_dlst, new_elem);*/
/*	return (new_elem);*/
/*}*/
/**/
/*t_dlist	*ft_dlstmap(t_dlist *dlst, void *(*f)(void *), void (*del)(void *))*/
/*{*/
/*	t_dlist	*new_dlst;*/
/*	void	*new_content;*/
/**/
/*	if (!dlst || !f)*/
/*		return (NULL);*/
/*	new_dlst = NULL;*/
/*	while (dlst)*/
/*	{*/
/*		new_content = f(dlst->content);*/
/*		if (!new_content)*/
/*		{*/
/*			ft_dlstclear(&new_dlst, del);*/
/*			return (NULL);*/
/*		}*/
/*		if (!create_and_add_elem(&new_dlst, new_content, del))*/
/*			return (NULL);*/
/*		dlst = dlst->next;*/
/*	}*/
/*	return (new_dlst);*/
/*}*/
