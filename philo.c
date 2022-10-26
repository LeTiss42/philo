/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/10/26 17:00:55 by mravera          ###   ########.fr       */
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
	printf("tt_d = %d\n", tt.tt_e);
	test = "t1";
	test2 = "t2";
	pthread_create(&t1, NULL, &routine, test);
	pthread_create(&t2, NULL, &routine, test2);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	(void)argc;
	(void)argv;
	return (1);
}
