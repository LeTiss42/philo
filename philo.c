/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/05 19:32:35 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_piz(t_admin *admin);

int	main(int argc, char **argv)
{
	t_admin			x;
	int				i;

	i = 0;
	if (pl_parsing(argc, argv, &x) == 1)
		printf("Parsing ok\n");
	else
		return (0);
	if (pl_init_piz(&x) == 1)
		printf("init ok\n");
	else
	{
		printf("Init error, aborting.\n");
		pl_free_all_piz(&x);
		return (0);
	}
	pl_free_all_piz(&x);
	return (1);
}

void	print_philo_piz(t_admin *admin)
{
	int	i;

	i = 0;
	printf("Start_time = %ld\n\n", admin->start_time);
	while (i < admin->nb_philo)
	{
		printf("Fork nb%d = %p\n", i, &admin->philo[i].own_fork);
		printf("  Last_time = %ld\n", admin->philo[i].last_time);
		i++;
	}
}
