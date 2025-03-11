/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 01:17:32 by yousef            #+#    #+#             */
/*   Updated: 2025/03/10 03:24:08 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	freevars(t_vars *vars, int i)
{
	if (i == 1)
		vars->exit = 2;
	if (i >= 2)
	{
		if (i >= 3)
		{
			while (--vars->counter >= 0)
				free(vars->philos[vars->counter]);
			vars->exit = 4;
		}
		vars->exit = 3;
		i = 0;
		while (i < vars->philos_num)
			pthread_mutex_destroy(&vars->forks[i++]);
	}
	pthread_mutex_destroy(vars->p_mutex);
	pthread_mutex_destroy(vars->stop_mutex);
	pthread_mutex_destroy(vars->death_mutex);
	free(vars->death_mutex);
	free(vars->stop_mutex);
	free(vars->p_mutex);
	free(vars->forks);
	free(vars->philos);
	return (0);
}
