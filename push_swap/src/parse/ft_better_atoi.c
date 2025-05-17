/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_better_atoi.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tstephan <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/17 10:28:57 by tstephan          #+#    #+#             */
/*   Updated: 2025/05/17 10:28:58 by tstephan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/push_swap.h"

static bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\f' || c == '\n' || c == '\r' || c == '\t'
		|| c == '\v');
}

static bool	ft_isdigit(char c)
{
	return (c >= '0' && c <= '9');
}

static bool	strict_atoll(const char *s, long long *result)
{
	long long	nbr;
	int			sign;

	nbr = 0;
	sign = 1;
	while (*s && ft_isspace(*s))
		s++;
	if (*s == '-' || *s == '+')
	{
		if (*s == '-')
			sign = -1;
		s++;
	}
	if (!*s || !ft_isdigit(*s))
		return (false);
	while (*s)
	{
		if (!ft_isdigit(*s))
			return (false);
		nbr = nbr * 10 + (*s - '0');
		s++;
	}
	*result = nbr * sign;
	return (true);
}

bool	strict_atoi(const char *s, int *result)
{
	long long	tmp;

	if (!strict_atoll(s, &tmp))
		return (false);
	if (tmp < INT_MIN || tmp > INT_MAX)
		return (false);
	*result = (int)tmp;
	return (true);
}
