/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:57:28 by yousef            #+#    #+#             */
/*   Updated: 2025/03/05 06:38:37 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int sleeping(t_philo *philos)
{
    if (starvation_ch(philos))
		return (1);

    pthread_mutex_lock(philos->p_mutex);
    printf("%ld philo number %d is sleeping\n", get_current_time_in_ms() - philos->sim_start, philos->philo_num);
    diy_sleep(get_current_time_in_ms(), philos->sleep_t, philos);
    pthread_mutex_unlock(philos->p_mutex);
    return (0);
}

int thinking(t_philo *philos)
{
    if (starvation_ch(philos))
		return (1);
    pthread_mutex_lock(philos->p_mutex);
    printf("%ld philo number %d is thinking\n", get_current_time_in_ms() - philos->sim_start, philos->philo_num);
    pthread_mutex_unlock(philos->p_mutex);
    return (0);
}

int eating(t_philo *philo)
{
    forks_lock(philo);
    if (starvation_ch(philo))
	{
		forks_unlock(philo);
		return (1);
	}
	pthread_mutex_lock(philo->p_mutex);
	printf(" %ld ms  %d has taken a fork \n", get_current_time_in_ms()
		- philo->sim_start, philo->philo_num);
	printf(" %ld ms  %d has taken a fork \n", get_current_time_in_ms()
		- philo->sim_start, philo->philo_num);
	printf(" %ld ms  %d is eating \n", get_current_time_in_ms() - philo->sim_start,
		philo->philo_num);
    pthread_mutex_unlock(philo->p_mutex);
    philo->last_meal = get_current_time_in_ms();
    diy_sleep(get_current_time_in_ms(), philo->eat_t, philo);
    forks_unlock(philo);
    philo->meals_eaten++;
    if (philo->meals_eaten == philo->meals)
        return (1);
    return (0);
}

int starvation_ch(t_philo *philos)
{
    pthread_mutex_lock(philos->death_mutex);
    if (get_current_time_in_ms() - philos->last_meal > philos->die_t)
    {
        printf("%ld philo number %d died\n", get_current_time_in_ms() - philos->sim_start, philos->philo_num);
        philos->state = 1;
    }
    pthread_mutex_unlock(philos->death_mutex);
    return (philos->state);
}