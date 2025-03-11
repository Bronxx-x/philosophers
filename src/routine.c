/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:29:02 by yousef            #+#    #+#             */
/*   Updated: 2025/03/12 02:43:38 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	forks_lock(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_lock(philo->lf_mutex);
		pthread_mutex_lock(philo->rf_mutex);
	}
	else
	{
		pthread_mutex_lock(philo->rf_mutex);
		pthread_mutex_lock(philo->lf_mutex);
	}
}

void	forks_unlock(t_philo *philo)
{
	if (philo->philo_num % 2 == 0)
	{
		pthread_mutex_unlock(philo->lf_mutex);
		pthread_mutex_unlock(philo->rf_mutex);
	}
	else
	{
		pthread_mutex_unlock(philo->rf_mutex);
		pthread_mutex_unlock(philo->lf_mutex);
	}
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	philo->sim_start = get_current_time_in_ms();
	if (philo->lf_mutex == philo->rf_mutex)
	{
		thinking(philo);
		while (!starvation_ch(philo))
			;
		return (NULL);
	}
	while (1)
	{
		if (eating(philo))
			break ;
		if (sleeping(philo))
			break ;
		if (thinking(philo))
			break ;
	}
	return (NULL);
}

void	threading(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->philos_num > i)
	{
		vars->err_ch = pthread_create(&vars->philos[i]->thread, NULL, routine,
				vars->philos[i]);
		if (vars->err_ch)
		{
			pthread_mutex_lock(vars->stop_mutex);
			usleep(vars->die_t * 1000);
			pthread_mutex_unlock(vars->p_mutex);
			break ;
		}
		usleep(100);
		i++;
	}
	vars->j = 0;
	while (i > vars->j)
		pthread_join(vars->philos[vars->j++]->thread, NULL);
	if (vars->died != -1)
		who_died(vars);
	if (i != vars->philos_num)
		freevars(vars, 3);
}
