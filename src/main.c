/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:06 by yhamdan           #+#    #+#             */
/*   Updated: 2025/03/10 04:59:30 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	mutex_init(t_vars *vars)
{
	vars->philos[vars->counter] = malloc(sizeof(t_philo));
	if (!vars->philos[vars->counter])
		freevars(vars, 1);
	vars->philos[vars->counter]->p_mutex = vars->p_mutex;
	vars->philos[vars->counter]->death_mutex = vars->death_mutex;
	vars->philos[vars->counter]->lf_mutex = &vars->forks[vars->counter];
	vars->philos[vars->counter]->rf_mutex = &vars->forks[(vars->counter + 1) % vars->philos_num];
	vars->philos[vars->counter]->died = &vars->died;
	vars->philos[vars->counter]->funeral = -1;
}

void	philo_init(t_vars *vars)
{
	vars->died = -1;
	vars->err_ch = pthread_mutex_init(vars->stop_mutex, NULL);
	vars->err_ch = pthread_mutex_init(vars->p_mutex, NULL);
	vars->err_ch = pthread_mutex_init(vars->death_mutex, NULL);
	if (vars->err_ch)
		freevars(vars, 2);
	if (vars->exit > 0)
		return ;	
	vars->counter = -1;
	while (++vars->counter < vars->philos_num)
	{
		mutex_init(vars);
		if (vars->exit > 0)
			return ;
		vars->philos[vars->counter]->die_t = vars->die_t;
		vars->philos[vars->counter]->eat_t = vars->eat_t;
		vars->philos[vars->counter]->sleep_t = vars->sleep_t;
		vars->philos[vars->counter]->philo_num = vars->counter + 1;
		vars->philos[vars->counter]->meals = vars->num_of_meals;
		vars->philos[vars->counter]->meals_eaten = 0;
		vars->philos[vars->counter]->last_meal = vars->sim_start;
		vars->philos[vars->counter]->state = 0;
		vars->philos[vars->counter]->sim_start = vars->sim_start;
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
	vars->forks = malloc(sizeof(pthread_mutex_t) * vars->philos_num);
	vars->philos = malloc(sizeof(t_philo *) * vars->philos_num);
	vars->stop_mutex = malloc(sizeof(pthread_mutex_t));
	vars->p_mutex = malloc(sizeof(pthread_mutex_t));
	vars->death_mutex = malloc(sizeof(pthread_mutex_t));
	if (!vars->stop_mutex || !vars->p_mutex || !vars->philos || !vars->forks || !vars->death_mutex)
		freevars(vars, 1);
	vars->counter = -1;
	while (++vars->counter < vars->philos_num)
	{
		vars->err_ch = pthread_mutex_init(&vars->forks[vars->counter], NULL);
		if (vars->err_ch)
			freevars(vars, 2);
	}
	if (vars->exit <= 0)
		philo_init(vars);
}

int	args_ch(int argc, char **argv)
{
	int	i;
	int	j;
	int ch;
	
	i = 1;
	ch = 0;
	if (!(argc == 5 || argc == 6))
		ch = 1;
	else
		ch = 0;
	while (ch == 0 && argv[i])
	{
		j = 0;
		if (argv[i][0] == '0')
			ch = 1;
		while (ft_isdigit(argv[i][j]))
			j++;
		if (j != (int)ft_strlen(argv[i]))
			ch = 1;
		i++;
	}
	if (ch == 1)
		printf("invalid arguments\n");
	return (ch);
}

int main (int argc, char *argv[])
{
	t_vars vars;
	
	vars.argc = argc;
	vars.exit = 0;
	if (args_ch(argc, argv))
		return (1);
	varsinit(&vars, argv);
	usleep(150);
	if (vars.exit <= 0)
		freevars(&vars, 3);
	return (0);
}