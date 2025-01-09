/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/07 16:43:54 by yousef            #+#    #+#             */
/*   Updated: 2025/01/07 17:10:47 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_current_time_in_ms(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}



int main (void)
{
    long sims = get_current_time_in_ms();
    int i = 1;
    printf("%ld\n", get_current_time_in_ms);
    while (i < 100)
    i++;
    printf("%ld\n", get_current_time_in_ms - sims);
    return (0);
}