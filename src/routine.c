/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/15 04:29:02 by yousef            #+#    #+#             */
/*   Updated: 2025/01/24 05:08:57 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    forks_lock(t_philo *philo)
{
    if (philo->fork1 < philo->fork2)
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

void    forks_unlock(t_philo *philo)
{
    if (philo->fork1 < philo->fork2)
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

void    threading(t_vars *vars)
{
    int i;

    i = 0;
    while (vars->philos_num > i)
    {
        vars->err_ch = pthread_create(&vars->philos[i]->thread, NULL, routine, (void *)vars->philos[i]);
        if (vars->err_ch)
        {
            pthread_mutex_lock(vars->stop_mutex);
                usleep(vars->die_t);
            pthread_mutex_unlock(vars->p_mutex);
            break ;
        }
        i++;
    }
    vars->j = 0;
    while (i > vars->j)
        pthread_join(vars->philos[vars->j++]->thread, NULL);
    if (i != vars->philos_num)
        freevars(vars, 3);
}

void	*routine(void *arg)
{
    t_philo	*philo;

    philo = (t_philo *)arg;
    while (1)
    {
        if (eating(philo))
            break ;
        if (starvation_ch(philo))
            break ;
    }
    return (NULL);
}