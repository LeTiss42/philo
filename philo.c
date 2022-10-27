/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/10/27 18:07:19 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *args)
{
	printf("Test = %s\n", (char *)args);
	usleep(1000000);
	printf("End = %s\n", (char *)args);
	return (NULL);
}

int	main(int argc, char **argv)
{
	pthread_t	t1;
	pthread_t	t2;
	char		*test;
	char		*test2;
	t_args		tt;

	tt = (t_args){0};
	pl_parsing(argc, argv, &tt);
	test = "t1";
	test2 = "t2";
	pthread_create(&t1, NULL, &routine, test);
	pthread_create(&t2, NULL, &routine, test2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	(void)argc;
	(void)argv;
	printf("1 = %d\n", tt.nb_philo);
	printf("2 = %d\n", tt.tt_d);
	printf("3 = %d\n", tt.tt_e);
	printf("4 = %d\n", tt.tt_s);
	printf("5 = %d\n", tt.nb_meal);
	return (1);
}
