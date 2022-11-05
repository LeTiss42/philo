/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:20:56 by mravera           #+#    #+#             */
/*   Updated: 2022/11/04 16:50:22 by mravera          ###   ########.fr       */
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
	printf("Malloc admin = %p\n", admin->philo);
	admin->start_time = pl_get_ms_time();
	while (i < admin->nb_philo)
	{
		if (pthread_mutex_init(&admin->philo[i].own_fork, NULL) != 0)
			return (-1);
		admin->philo[i].last_time = admin->start_time - pl_get_ms_time();
		if (pthread_create(&admin->philo[i].th, NULL, &func, admin) != 0)
			return (-1);
		printf("%d started\n", i);
		i++;
	}
	return (1);
}

/*
int	pl_init_all(t_admin *x, int nb_philo)
{
	int	i;

	i = 1;
	x->start_time = pl_get_ms_time();
	while (i <= nb_philo)
	{
		if (pl_add_philo(x, i) == -1)
			return (-1);
		i++;
	}
	return (0);
}

int	pl_add_philo(t_admin *x, int num)
{
	t_philo	*temp;

	if (num == 1)
	{
		if (pl_add_first_philo(x) == -1)
			return (-1);
	}
	else if (pl_add_any_philo(x, x->first_philo, num) == -1)
		return (-1);
	temp = x->first_philo;
	while (temp->next != NULL)
	{
		temp->next_fork = &temp->next->own_fork;
		temp = temp->next;
	}
	return (0);
}

int	pl_add_first_philo(t_admin *x)
{
	t_philo	*temp;

	temp = malloc(sizeof(t_philo));
	if (temp == NULL)
		return (-1);
	printf("first malloc = %p\n", temp);
	temp->num = 1;
	temp->last_time = pl_get_ms_time() - x->start_time;
	temp->next = NULL;
	if (pthread_mutex_init(&temp->own_fork, NULL) != 0)
		return (-1);
	printf("first fork = %p\n\n", &(temp->own_fork));
	temp->next_fork = NULL;
	x->first_philo = temp;
	return (0);
}

int	pl_add_any_philo(t_admin *admin, t_philo *x, int num)
{
	t_philo	*temp;
	t_philo	*i;

	i = x;
	temp = malloc(sizeof(t_philo));
	if (temp == NULL)
		return (-1);
	printf("philo malloc = %p\n", temp);
	temp->num = num;
	temp->last_time = pl_get_ms_time() - admin->start_time;
	temp->next = NULL;
	if (pthread_mutex_init(&temp->own_fork, NULL) != 0)
		return (-1);
	printf("fork init = %p\n\n", &(temp->own_fork));
	temp->next_fork = NULL;
	while (i->next != NULL)
		i = i->next;
	i->next = temp;
	return (0);
}
*/