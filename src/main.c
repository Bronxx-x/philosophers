/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yousef <yousef@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:06 by yhamdan           #+#    #+#             */
/*   Updated: 2025/01/07 18:04:03 by yousef           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	varsinit(t_vars *vars, char **argv)
{
	vars->philos_num = ft_atoi(argv[1]);
	vars->die_t = ft_atoi(argv[2]);
	vars->eat_t = ft_atoi(argv[3]);
	vars->sleep_t = ft_atoi(argv[4]);
	vars->threads = malloc(sizeof(t_philo *) * vars->philos_num);
	vars->fork = malloc(sizeof(t_philo *) * vars->philos_num);	
	//vars->sim_start = get_current_time_in_ms();
	
}

int	args_ch(int arg, char **argv)
{
	int	i;
	int	j;
	int ch;
	
	i = 1;
	ch = 0;
	if (arg != 5)
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