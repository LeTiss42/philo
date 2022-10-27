/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:28 by mravera           #+#    #+#             */
/*   Updated: 2022/10/27 18:07:48 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <unistd.h>

typedef struct s_args
{
	int	nb_philo;
	int	tt_d;
	int	tt_e;
	int	tt_s;
	int	nb_meal;
}	t_args;

//pl_parsing
int	pl_parsing(int argc, char **argv, t_args *args);
int	pl_check_argc(int argc);
int	pl_parse_argv(char **argv, t_args *args);

#endif