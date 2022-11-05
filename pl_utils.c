/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:10:29 by mravera           #+#    #+#             */
/*   Updated: 2022/11/05 18:49:32 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_atoi(const char *nptr)
{
	int				i;
	int				sign;
	unsigned int	res;

	sign = 1;
	i = 0;
	res = 0;
	while ((9 <= nptr[i] && nptr[i] <= 13) || (nptr[i] == ' '))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+')
	{
		if (nptr[i] == '-')
			sign = sign * -1;
		i++;
	}
	while (pl_isdigit(nptr[i]))
	{
		res = (res * 10) + (nptr[i++] - 48);
		if (res > 2147483648 || (res == 2147483648 && sign == 1))
			printf("MaxInt overload spotted\nExpect unexpected behaviours\n");
	}
	return (sign * res);
}

int	pl_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

void	pl_free_all_piz(t_admin *admin)
{
	int	i;

	i = 0;
	while (i < admin->nb_philo)
	{
		printf("Destroying fork nb%d addr = %p\n", i, &admin->philo[i].own_fork);
		if (pthread_mutex_destroy(&admin->philo[i].own_fork) != 0)
			printf("Error\nProblem destroying mutex!\n");
		i++;
	}
	printf("Freing admin = %p\n", admin->philo);
	free(admin->philo);
	printf("all freed up!\n");
	return ;
}
