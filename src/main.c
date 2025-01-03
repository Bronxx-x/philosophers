/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhamdan <yhamdan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/04 00:24:06 by yhamdan           #+#    #+#             */
/*   Updated: 2025/01/04 01:22:12 by yhamdan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

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
	if (args_ch(arg, argv));
		return (1);
	
	return (0);
}