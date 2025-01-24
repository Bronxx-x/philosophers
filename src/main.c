/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:06 by yhamdan           #+#    #+#             */
/*   Updated: 2025/01/24 05:04:59 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_current_time_in_ms(void)
{
    struct timeval time;
    gettimeofday(&time, NULL);
    return (time.tv_sec * 1000) + (time.tv_usec / 1000);
}

void	philo_init(t_vars *vars)
{
	vars->counter = 0;
	while (vars->philos_num > vars->counter)
	{
		vars->philos[vars->counter]->die_t = vars->die_t;
		vars->philos[vars->counter]->eat_t = vars->eat_t;
		vars->philos[vars->counter]->sleep_t = vars->sleep_t;
		vars->philos[vars->counter]->philo_num = vars->counter + 1;
		vars->philos[vars->counter]->meals = vars->num_of_meals;
		vars->philos[vars->counter]->meals_eaten = 0;
		vars->philos[vars->counter]->last_meal = vars->sim_start;
		vars->philos[vars->counter]->state = 0;
		vars->philos[vars->counter]->fork1 = (vars->counter + 1) % 2;
		vars->philos[vars->counter]->fork2 = vars->counter % 2;
		vars->err_ch = pthread_mutex_init(vars->philos[vars->counter]->lf_mutex, NULL);
		vars->err_ch = pthread_mutex_init(vars->philos[vars->counter]->rf_mutex, NULL);
		vars->err_ch = pthread_mutex_init(vars->philos[vars->counter]->p_mutex, NULL);
		vars->err_ch = pthread_mutex_init(vars->philos[vars->counter]->death_mutex, NULL);
		if (vars->err_ch)
			freevars(vars, 3);
		vars->counter++;
	}
	threading(vars);
}

void	varsinit(t_vars *vars, char **argv)
{
	vars->philos_num = ft_atoi(argv[1]);
	vars->die_t = ft_atoi(argv[2]);
	vars->eat_t = ft_atoi(argv[3]);
	vars->sleep_t = ft_atoi(argv[4]);
	if (argv[5])
		vars->num_of_meals = ft_atoi(argv[5]);
	else
		vars->num_of_meals = -1;
	vars->sim_start = get_current_time_in_ms();
		vars->philos = malloc(sizeof(t_philo *));
	vars->philos = malloc(sizeof(t_philo) * vars->philos_num);
	vars->stop_mutex = malloc(sizeof(pthread_mutex_t));
	vars->p_mutex = malloc(sizeof(pthread_mutex_t));
	if (!vars->philos || !vars->stop_mutex || !vars->p_mutex)
		freevars(vars, 1);
	vars->err_ch = pthread_mutex_init(vars->stop_mutex, NULL);
	vars->err_ch = pthread_mutex_init(vars->p_mutex, NULL);
	if (vars->err_ch)
		freevars(vars, 2);
	philo_init(vars);
}

int	args_ch(int arg, char **argv)
{
	int	i;
	int	j;
	int ch;
	
	i = 1;
	ch = 0;
	if (!(arg == 5 || arg == 6))
		ch = 0;
	else
	ch = 1;
	while (ch == 0 && argv[i])
	{
		j = 0;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (j != ft_strlen(argv[i]))
			ch = 1;
		i++;
	}
	if (ch == 1)
		printf("invalid arguments\n");
	return (ch);
}

int main (int arg, char *argv[])
{
	t_vars vars;
	
	if (args_ch(arg, argv));
		return (1);
	varsinit(&vars, argv);
	
	return (0);
}