/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/09 14:32:41 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo_piz(t_admin *admin);

int	main(int argc, char **argv)
{
	t_admin			x;
	int				i;

	i = 0;
	if (pl_parsing(argc, argv, &x) != 1)
	{
		printf("Parsing error.\n");
		return (0);
	}
	//printf("admin addr = %p\n", &x);
	if (pl_init_piz(&x) != 1)
	{
		printf("Init error, aborting.\n");
		return (0);
	}
	pl_check_end(x.philo);
	//print_philo_piz(&x);
	pl_free_all_piz(&x);
	return (1);
}

void	pl_check_end(t_philo *philo)
{
	int	i;

	i = 0;
	while (philo->adm->is_end == 0)
	{
		if (i == philo->adm->nb_philo)
		{
			i = 0;
			philo->adm->eat_ok = 1;
		}
		if ((pl_get_now(philo[i].adm) - philo[i].last_time) >= philo->adm->tt_d)
		{
			philo[i].adm->is_end = 1;
			printf("%ld %d died\n", pl_get_now(philo[i].adm), philo[i].num);
		}
		if (philo[i].nb_eat < philo[i].adm->nb_meal)
			philo->adm->eat_ok = 0;
		i++;
		if ((i == philo->adm->nb_philo) && (philo->adm->eat_ok == 1)
			&& (philo->adm->nb_meal > 0))
		{
			philo->adm->is_end = 1;
			printf("everyone has eaten %d times!\n", philo->adm->nb_meal);
		}
	}
}

void	print_philo_piz(t_admin *admin)
{
	int		i;
	t_philo	*p;

	p = admin->philo;
	i = 0;
	usleep(100000);
	printf("\n\nStart_time = %ld\n", admin->start_time);
	printf("\n\nadmin addr = %p\n", admin);
	while (i < admin->nb_philo)
	{
		printf("\n\n___________________________\n");
		printf("own adrr = %p\n", p);
		printf("num = %d nb_eat = %d\nlast_time = %ld\nnext = %p\n",
			p[i].num, p[i].nb_eat,
			p[i].last_time, p[i].next);
		printf("th = %p\nown__fork = %p\nnext_fork %p\n", p[i].th,
			&p[i].own_fork, &p[i].next->own_fork);
		printf("adm ptr = %p\n", p[i].adm);
		printf("___________________________\n");
		i++;
	}
}
