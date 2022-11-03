/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:24:49 by mravera           #+#    #+#             */
/*   Updated: 2022/11/03 12:13:45 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *admin)
{
	t_admin	*temp;

	temp = (t_admin *)admin;
	printf("Start = %ld\n", pl_get_ms_time());
	usleep(2000000);
	printf("End = %ld\n", pl_get_ms_time() - temp->start_time);
	return (NULL);
}
