/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:54 by yousef            #+#    #+#             */
/*   Updated: 2025/03/12 22:34:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time_in_ms(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	diy_sleep(long time, long action_time, t_philo *philo)
{
	long	cur;

	cur = get_current_time_in_ms();
	while (cur - time < action_time)
	{
		cur = get_current_time_in_ms();
		usleep(100);
		while (cur < time)
			cur = get_current_time_in_ms();
		if (starvation_ch(philo))
			break ;
	}
	return (0);
}
