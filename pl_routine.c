/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:24:49 by mravera           #+#    #+#             */
/*   Updated: 2022/11/07 00:42:54 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->num % 2 == 0)
		usleep(50);
	while (p->adm->is_end == 0)
	{
		philo_eat(p);
		if (p->adm->is_end == 0)
			philo_sleep(p);
		if (p->adm->is_end == 0)
			philo_think(p);
	}
	return (NULL);
}

void	philo_eat(t_philo *philo)
{
	if (pthread_mutex_lock(&philo->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	if (philo->adm->is_end == 0)
		printf("%ld %d has taken a fork\n", pl_get_now(philo->adm), philo->num);
	if (pthread_mutex_lock(&philo->next->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	if (philo->adm->is_end == 0)
		printf("%ld %d is eating\n", pl_get_now(philo->adm), philo->num);
	usleep(philo->adm->tt_e * 1000);
	if (pthread_mutex_unlock(&philo->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	if (pthread_mutex_unlock(&philo->next->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	return ;
}

void	philo_sleep(t_philo *philo)
{
	if (philo->adm->is_end == 0)
		printf("%ld %d is sleeping\n", pl_get_now(philo->adm), philo->num);
	usleep(philo->adm->tt_s * 1000);
	return ;
}

void	philo_think(t_philo *philo)
{
	if (philo->adm->is_end == 0)
		printf("%ld %d is thinking\n", pl_get_now(philo->adm), philo->num);
}
