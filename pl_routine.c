/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_routine.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/28 18:24:49 by mravera           #+#    #+#             */
/*   Updated: 2022/11/05 20:16:58 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*func(void *philo)
{
	printf("___________________________\n");
	printf("own adrr = %p\n", philo);
	printf("num = %d\nlast_time = %ld\nnext = %p\n", ((t_philo *)philo)->num,
		((t_philo *)philo)->last_time, ((t_philo *)philo)->next);
	printf("th = %p\nown__fork = %p\nnext_fork %p\n", ((t_philo *)philo)->th,
		&((t_philo *)philo)->own_fork, &((t_philo *)philo)->next->own_fork);
	printf("___________________________\n");
	return (NULL);
}
