/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:28:50 by mravera           #+#    #+#             */
/*   Updated: 2022/10/28 20:38:21 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_args			tt;
	t_admin			admintest;
	struct timeval	tv;

	admintest = (t_admin){0};
	gettimeofday(&tv, NULL);
	printf("tv_sec  = %ld\n", tv.tv_sec);
	printf("tv_usec = %d\n", tv.tv_usec);
	tt = (t_args){0};
	printf("parsing = %d\n", pl_parsing(argc, argv, &tt));
	printf("1 = %d\n", tt.nb_philo);
	printf("2 = %d\n", tt.tt_d);
	printf("3 = %d\n", tt.tt_e);
	printf("4 = %d\n", tt.tt_s);
	printf("5 = %d\n", tt.nb_meal);
	return (1);
}
