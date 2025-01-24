/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/24 04:57:28 by yousef            #+#    #+#             */
/*   Updated: 2025/01/24 05:07:35 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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