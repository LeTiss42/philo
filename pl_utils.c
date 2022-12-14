/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 18:10:29 by mravera           #+#    #+#             */
/*   Updated: 2022/11/09 16:15:02 by mravera          ###   ########.fr       */
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
	while (nptr[i] == '-' || nptr[i] == '+')
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
	usleep((admin->tt_d + admin->tt_e + admin->tt_s + 100) * 1000);
	while (i < admin->nb_philo)
	{
		if (pthread_mutex_destroy(&admin->philo[i].own_fork) != 0)
			printf("Error\nProblem destroying mutex!\n");
		i++;
	}
	free(admin->philo);
	return ;
}
