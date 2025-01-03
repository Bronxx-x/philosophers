/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:27 by yhamdan           #+#    #+#             */
/*   Updated: 2025/01/04 01:20:42 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <sys/time.h>
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>


typedef struct s_philo
{
	pthread_t		thread;
	long			last_meal;
	int				state;
	int				philo_num;
	int				fork1;
	int				fork2;
	struct s_philo	*philo_data;
}					t_philo;

typedef struct s_fork
{
	int				is_used;
	pthread_mutex_t	mutex;
}					t_fork;

typedef struct s_vars
{
	int				philos_count;
	int				t_to_die;
	int				t_to_eat;
	int				t_to_sleep;
	int				sim_stop;
	long			start_time;
	t_fork	*fork;
	t_philo	*process;
	pthread_mutex_t	sim_stop_mutex;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t	log_mutex;
}					t_vars;

int		starvation_sleeping_check(t_philo *philo);
size_t	ft_strlen(const char *str);
long	ft_atoi(const char *str);
int		ft_isdigit(int c);
int		args_ch(int arg, char **argv);
/*
long	get_time_in_ms(void);
void	philo_error_handling(t_vars *vars, int num, int error);
void	check_input(char *argv[], int argc);
void	forks_lock(t_philo *philo, int fork1, int fork2);
int		my_usleep(t_philo *philo, int time);
void	get_fork_num(t_philo *philo, int *fork1, int *fork2);
int		check_starvation(t_philo *philo, long time_now);
void	write_status(t_philo *philo, int status);
void	kill_the_rest(t_vars *vars);
*/
void	*routine(void *arg);

#endif
