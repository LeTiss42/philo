/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/10/30 23:00:08 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_admin			x;

	if (pl_parsing(argc, argv, &x.args) == 1)
		printf("Parsing ok\n");
	if (pl_init_all(&x, 1) == 1)
		printf("init ok\n");
	pl_init_all(&x, 5);
	printf("last_time = %ld\nptr = %p\n", x.first_philo->last_time, x.first_philo);
	printf("next = %p\n", x.first_philo->next);
	return (1);
}
