/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/02 17:36:08 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	print_philo(t_admin *admin);
void	print_philo_piz(t_admin *admin);

int	main(int argc, char **argv)
{
	t_admin			x;

	if (pl_parsing(argc, argv, &x) == 1)
		printf("Parsing ok\n");
	if (pl_init_piz(&x) == 1)
		printf("init ok\n");
	print_philo_piz(&x);
	pl_free_all_piz(&x);
	return (1);
}

void	print_philo(t_admin *admin)
{
	t_philo	*p;

	p = admin->first_philo;
	printf("\n---------------\n");
	while (p->next != NULL)
	{
		printf("ptr philo num%d = %p\nnext philo = %p\nlast_time = %ld\n"
			"fork = %p\nnext fork = %p\n\n",
			p->num, p, p->next, p->last_time, &(p->own_fork), p->next_fork);
		p = p->next;
	}
	printf("ptr philo num%d = %p\nnext philo = %p\nlast_time = %ld\n"
		"fork = %p\nnext fork = %p\n\n",
		p->num, p, p->next, p->last_time, &(p->own_fork), p->next_fork);
	printf("---------------\n");
	return ;
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
