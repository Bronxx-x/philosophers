/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:57:28 by yousef            #+#    #+#             */
/*   Updated: 2025/03/12 00:41:17 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	sleeping(t_philo *philos)
{
	if (starvation_ch(philos))
		return (1);
	pthread_mutex_lock(philos->p_mutex);
	printf(" %ld ms, philo number %d is sleeping\n", get_current_time_in_ms()
		- philos->sim_start, philos->philo_num);
	pthread_mutex_unlock(philos->p_mutex);
	if (diy_sleep(get_current_time_in_ms(), philos->sleep_t, philos))
		return (1);
	return (0);
}

int	thinking(t_philo *philos)
{
	usleep(100);
	if (starvation_ch(philos))
		return (1);
	pthread_mutex_lock(philos->p_mutex);
	printf(" %ld ms, philo number %d is thinking\n", get_current_time_in_ms()
		- philos->sim_start, philos->philo_num);
	pthread_mutex_unlock(philos->p_mutex);
	return (0);
}

int	eating(t_philo *philo)
{
	forks_lock(philo);
	if (starvation_ch(philo))
	{
		forks_unlock(philo);
		return (1);
	}
	usleep(50);
	pthread_mutex_lock(philo->p_mutex);
	printf(" %ld ms, philo number %d has taken a fork \n",
		get_current_time_in_ms() - philo->sim_start, philo->philo_num);
	printf(" %ld ms, philo number %d has taken a fork \n",
		get_current_time_in_ms() - philo->sim_start, philo->philo_num);
	printf(" %ld ms, philo number %d is eating \n", get_current_time_in_ms()
		- philo->sim_start, philo->philo_num);
	pthread_mutex_unlock(philo->p_mutex);
	philo->last_meal = get_current_time_in_ms();
	if (diy_sleep(get_current_time_in_ms(), philo->eat_t, philo))
		return (1);
	forks_unlock(philo);
	philo->meals_eaten++;
	if (philo->meals_eaten == philo->meals)
		return (1);
	return (0);
}

int	starvation_ch(t_philo *philos)
{
	pthread_mutex_lock(philos->death_mutex);
	if (get_current_time_in_ms() - philos->last_meal > philos->die_t
		|| *(philos->died) != -1)
	{
		philos->funeral = get_current_time_in_ms() - philos->sim_start;
		if (*(philos->died) == -1)
			*(philos->died) = philos->philo_num;
		philos->state = 1;
		pthread_mutex_unlock(philos->death_mutex);
		usleep(100);
	}
	else
		pthread_mutex_unlock(philos->death_mutex);
	return (philos->state);
}

void	who_died(t_vars *vars)
{
	usleep(50);
	pthread_mutex_lock(vars->p_mutex);
	printf(" %ld ms, philo number %d died\n", get_current_time_in_ms()
		- vars->sim_start, vars->died);
	pthread_mutex_unlock(vars->p_mutex);
}
