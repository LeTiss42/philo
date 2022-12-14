/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:20:56 by mravera           #+#    #+#             */
/*   Updated: 2022/11/10 12:03:42 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_init_piz(t_admin *admin)
{
	int	i;

	i = 0;
	admin->philo = malloc(sizeof(t_philo) * admin->nb_philo);
	if (admin->philo == NULL)
	{
		printf("Malloc Error, unlucky...\n");
		return (0);
	}
	pl_set(admin);
	admin->start_time = pl_get_ms_time();
	admin->eat_ok = 1;
	while (i < admin->nb_philo)
	{
		if (pthread_mutex_init(&admin->philo[i].own_fork, NULL) != 0)
			return (-1);
		admin->philo[i].last_time = pl_get_ms_time() - admin->start_time;
		if (pthread_create(&admin->philo[i].th,
				NULL, &func, &admin->philo[i]) != 0)
			return (-1);
		i++;
	}
	return (1);
}

void	pl_set(t_admin *admin)
{
	int	i;

	i = 0;
	admin->is_end = 0;
	if (admin->nb_philo > 1)
	{
		while (i < admin->nb_philo)
		{
			admin->philo[i].num = i + 1;
			admin->philo[i].adm = admin;
			admin->philo[i].nb_eat = 0;
			if (i == (admin->nb_philo - 1))
				admin->philo[i].next = &admin->philo[0];
			else
				admin->philo[i].next = &admin->philo[i + 1];
			i++;
		}
	}
	else
		pl_set_one_philo(admin);
	return ;
}

void	pl_set_one_philo(t_admin *admin)
{
	admin->philo[0].next = NULL;
	admin->philo[0].num = 1;
	admin->philo[0].nb_eat = 0;
	admin->philo[0].adm = admin;
}
