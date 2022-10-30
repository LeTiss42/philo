/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:57:37 by mravera           #+#    #+#             */
/*   Updated: 2022/10/30 15:58:38 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_parsing(int argc, char **argv, t_args *args)
{
	if (pl_check_argc(argc) && pl_check_argv(argv))
		pl_parse_argv(argv, args);
	else
		return (0);
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

int	pl_parse_argv(char **argv, t_args *args)
{
	args->nb_philo = pl_atoi(argv[1]);
	args->tt_d = pl_atoi(argv[2]);
	args->tt_e = pl_atoi(argv[3]);
	args->tt_s = pl_atoi(argv[4]);
	if (argv[5] != NULL)
		args->nb_meal = (pl_atoi(argv[5]));
	else if (argv[5] == NULL)
		args->nb_meal = -1;
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
