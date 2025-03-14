/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:27 by yhamdan           #+#    #+#             */
/*   Updated: 2025/03/08 23:26:33 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_philo
{
	pthread_t		thread;
	long			last_meal;
	int				philo_num;
	int				state;
	int				*died;
	int				meals;
	int				meals_eaten;
	int				die_t;
	int				eat_t;
	int				sleep_t;
	long			funeral;
	long			sim_start;
	pthread_mutex_t	*rf_mutex;
	pthread_mutex_t	*lf_mutex;
	pthread_mutex_t	*p_mutex;
	pthread_mutex_t	*death_mutex;
}					t_philo;

typedef struct s_vars
{
	int				philos_num;
	int				num_of_meals;
	int				argc;
	int				j;
	int				die_t;
	int				died;
	int				eat_t;
	int				sleep_t;
	int				exit;
	int				err_ch;
	long			sim_start;
	int				init_counter;
	int				counter;
	pthread_mutex_t	*p_mutex;
	pthread_mutex_t	*forks;
	pthread_mutex_t	*stop_mutex;
	pthread_mutex_t	*death_mutex;
	t_philo			**philos;
}					t_vars;

int					starvation_ch(t_philo *philos);
size_t				ft_strlen(const char *str);
long				ft_atoi(const char *str);
int					ft_isdigit(int c);
int					args_ch(int arg, char **argv);
long				get_current_time_in_ms(void);
int					freevars(t_vars *vars, int i);
void				philo_init(t_vars *vars);
void				varsinit(t_vars *vars, char **argv);
void				*routine(void *arg);
void				threading(t_vars *vars);
int					eating(t_philo *philos);
int					starvation_ch(t_philo *philos);
void				forks_lock(t_philo *philo);
void				forks_unlock(t_philo *philo);
int					thinking(t_philo *philos);
int					sleeping(t_philo *philos);
long				diy_sleep(long time, long action_time, t_philo *philo);
void				who_died(t_vars *vars);

#endif
