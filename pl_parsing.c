/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pl_parsing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/27 14:57:37 by mravera           #+#    #+#             */
/*   Updated: 2022/10/27 17:51:25 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	pl_parsing(int argc, char **argv, t_args *args)
{
	if (pl_check_argc(argc))
		pl_parse_argv(argv, args);
	return ;
}

int	pl_check_argc(int argc)
{
	if (argc < 4)
	{
		printf("Too few args, need at least 4\n");
		return (0);
	}
	if (argc > 5)
	{
		printf("Too many arguments, max 5\n");
		return (0);
	}
	return (1);
}

int	pl_parse_argv(char **argv, t_args *args)
{
	int	i;

	args->nb_philo = atoi(argv[0]);
	args->tt_d = atoi(argv[1]);
	args->tt_e = atoi(argv[2]);
	args->tt_s = atoi(argv[3]);
	if (argv[4] != NULL)
		args->nb_meal = (atoi[4]);
	else if (argv[4] == NULL)
		args->nb_meal = 0;
	return (1);
}
