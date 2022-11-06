/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_set_time.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/30 17:03:38 by mravera           #+#    #+#             */
/*   Updated: 2022/11/06 22:02:02 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long int	pl_get_ms_time(void)
{
	struct timeval	tv;
	long int		res;

	if (gettimeofday(&tv, NULL) == -1)
		printf("Error calling function 'gettimeofday'.\n");
	res = tv.tv_sec * 1000;
	res = res + (tv.tv_usec / 1000);
	return (res);
}

long int	pl_get_now(t_admin *admin)
{
	long int	now;

	now = pl_get_ms_time() - admin->start_time;
	return (now);
}
