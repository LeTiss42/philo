/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 18:20:56 by mravera           #+#    #+#             */
/*   Updated: 2022/10/30 23:08:22 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_init_all(t_admin *x, int nb_philo)
{
	int	i;

	i = 1;
	while (i <= nb_philo)
	{
		printf("i = %d\n", i);
		if (pl_add_philo(x, i) == -1)
			return (-1);
		printf("XXXXX\n");
		i++;
		printf("IIIIII = %d\n", i);
	}
	return (0);
}

int	pl_add_philo(t_admin *x, int num)
{
	t_philo	*temp;

	if (num == 1)
	{
		printf("in = %d\n", num);
		if (pl_add_first_philo(x) == -1)
			return (-1);
	}
	else if (pl_add_any_philo(x->first_philo, num) == -1)
		return (-1);
	temp = x->first_philo;
	while (temp->next != NULL)
	{
		temp->next_fork = &temp->next->own_fork;
		temp = temp->next;
	}
	printf("testststst\n");
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
	temp->last_time = -666;
	temp->next = NULL;
	if (pthread_mutex_init(&temp->own_fork, NULL) != 0)
		return (-1);
	temp->next_fork = NULL;
	x->first_philo = temp;
	return (0);
}

int	pl_add_any_philo(t_philo *x, int num)
{
	t_philo	*temp;
	t_philo	*i;

	i = x;
	temp = malloc(sizeof(t_philo));
	if (temp == NULL)
		return (-1);
	printf("philo malloc = %p\n", temp);
	temp->num = num;
	temp->last_time = -666;
	temp->next = NULL;
	if (pthread_mutex_init(&temp->own_fork, NULL) != 0)
		return (-1);
	temp->next_fork = NULL;
	while (i->next != NULL)
		i = i->next;
	i->next = temp;
	return (0);
}
