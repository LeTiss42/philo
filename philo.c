/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/11/07 00:41:14 by mravera          ###   ########.fr       */
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
	printf("admin addr = %p\n", &x);
	if (pl_init_piz(&x) == 1)
		printf("init ok\n");
	else
	{
		printf("Init error, aborting.\n");
		return (0);
	}
	usleep(3000000);
	x.is_end = 1;
	usleep(1000000);
	print_philo_piz(&x);
	pl_free_all_piz(&x);
	return (1);
}

void	print_philo_piz(t_admin *admin)
{
	int		i;
	t_philo	*p;

	p = admin->philo;
	i = 0;
	printf("\n\nStart_time = %ld\n", admin->start_time);
	printf("admin addr = %p\n", admin);
	while (i < admin->nb_philo)
	{
		printf("___________________________\n");
		printf("own adrr = %p\n", p);
		printf("num = %d nb_eat = %d\nlast_time = %ld\nnext = %p\n",
			p[i].nb_eat, p[i].num,
			p[i].last_time, p[i].next);
		printf("th = %p\nown__fork = %p\nnext_fork %p\n", p[i].th,
			&p[i].own_fork, &p[i].next->own_fork);
		printf("adm ptr = %p\n", p[i].adm);
		printf("___________________________\n");
		i++;
	}
}
