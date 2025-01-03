/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/05 22:00:38 by yhamdan           #+#    #+#             */
/*   Updated: 2025/01/04 01:11:48 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *n)
{
	int			i;
	int			sign;
	long int	r;

	i = 0;
	sign = 1;
	r = 0;
	while (n[i] == ' ' || (n[i] >= 9 && n[i] <= 13))
		i++;
	if (n[i] == '-' || n[i] == '+')
	{
		if (n[i] == '-')
			sign *= -1;
		i++;
	}
	while (ft_isdigit(n[i]))
	{
		r *= 10;
		r += n[i] - '0';
		i++;
	}
	return (r * sign);
}

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

size_t	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}
