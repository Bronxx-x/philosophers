/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_error.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/12 01:17:32 by yousef            #+#    #+#             */
/*   Updated: 2025/01/24 05:05:18 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    freevars(t_vars *vars, int i)
{
    if (i == 1)
        printf("malloc failed\n");
    if (i >= 2)
    {
        if (i >= 3)
        {
            while (vars->counter >= 0)
            {
                pthread_mutex_destroy(vars->philos[vars->counter]->lf_mutex);
                pthread_mutex_destroy(vars->philos[vars->counter]->rf_mutex);
                pthread_mutex_destroy(vars->philos[vars->counter]->p_mutex);
                pthread_mutex_destroy(vars->philos[vars->counter]->death_mutex);
                free(vars->philos[vars->counter]);
                vars->counter--;
            }
        }
        pthread_mutex_destroy(vars->stop_mutex);
        pthread_mutex_destroy(vars->p_mutex);
        free(vars->philos);
    }
    exit(1);
}