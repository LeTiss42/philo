/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:57:37 by mravera           #+#    #+#             */
/*   Updated: 2022/11/08 19:51:56 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_parsing(int argc, char **argv, t_admin *admin)
{
	if (pl_check_argc(argc) && pl_check_argv(argv))
		pl_parse_argv(argv, admin);
	else
	{
		printf("Error\nFailed to parse arguments.\n");
		return (0);
	}
	/*
	printf("--------------------\n");
	printf("| nb philo      = %d\n", admin->nb_philo);
	printf("| time to die   = %d\n", admin->tt_d);
	printf("| time to eat   = %d\n", admin->tt_e);
	printf("| time to sleep = %d\n", admin->tt_s);
	printf("| nb of meal    = %d\n", admin->nb_meal);
	printf("--------------------\n");
	*/
	if (admin->nb_philo <= 0)
	{
		printf("Need at least 1 philosopher to start philosophizing\n");
		return (0);
	}
	return (1);
}

int	pl_check_argc(int argc)
{
	if (argc < 5)
	{
		printf("Too few args, need at least 4\n");
		return (0);
	}
	if (argc > 6)
	{
		printf("Too many arguments, max 5\n");
		return (0);
	}
	return (1);
}

int	pl_parse_argv(char **argv, t_admin *admin)
{
	admin->nb_philo = pl_atoi(argv[1]);
	admin->tt_d = pl_atoi(argv[2]);
	admin->tt_e = pl_atoi(argv[3]);
	admin->tt_s = pl_atoi(argv[4]);
	if (argv[5] != NULL)
		admin->nb_meal = (pl_atoi(argv[5]));
	else if (argv[5] == NULL)
		admin->nb_meal = -1;
	return (1);
}

int	pl_check_argv(char **argv)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (argv[i])
	{
		while (argv[i][j])
		{
			if (pl_isdigit(argv[i][j]) == 0 && argv[i][j] != '-')
			{
				printf("Other than digit arg spotted.\n");
				return (0);
			}
			j++;
		}
		if (pl_atoi(argv[i]) < 0)
		{
			printf("Negative arg spotted.\n");
			return (0);
		}
		i++;
		j = 0;
	}
	return (1);
}
