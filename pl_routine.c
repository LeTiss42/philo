/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:24:49 by mravera           #+#    #+#             */
/*   Updated: 2022/11/09 16:09:26 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *philo)
{
	t_philo	*p;

	p = philo;
	if (p->num % 2 == 0)
		pl_tenth_sleep(5);
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
	if (philo->adm->nb_philo == 1)
	{
		pl_msleep(philo->adm->tt_d + 10);
		if (pthread_mutex_unlock(&philo->own_fork) != 0)
			printf("Error\nMutex unknown.\n");
		return ;
	}
	if (pthread_mutex_lock(&philo->next->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	philo->last_time = pl_get_now(philo->adm);
	if (philo->adm->is_end == 0)
		printf("%ld %d is eating\n", pl_get_now(philo->adm), philo->num);
	pl_msleep(philo->adm->tt_e);
	if (pthread_mutex_unlock(&philo->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	if (pthread_mutex_unlock(&philo->next->own_fork) != 0)
		printf("Error\nMutex unknown.\n");
	return ;
}

void	philo_sleep(t_philo *philo)
{
	if (philo->adm->is_end == 0)
	{
		philo->nb_eat ++;
		printf("%ld %d is sleeping\n", pl_get_now(philo->adm), philo->num);
	}
	if (philo->adm->tt_s == 0)
		pl_tenth_sleep(5);
	pl_tenth_sleep(philo->adm->tt_s * 10);
	return ;
}

void	philo_think(t_philo *philo)
{
	if (philo->adm->is_end == 0)
		printf("%ld %d is thinking\n", pl_get_now(philo->adm), philo->num);
}
