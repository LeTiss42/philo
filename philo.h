/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mravera <mravera@student.42lausanne.ch>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/26 14:30:28 by mravera           #+#    #+#             */
/*   Updated: 2022/11/09 16:15:33 by mravera          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/time.h>
# include <limits.h>

typedef struct s_philo
{
	int				num;
	long int		last_time;
	struct s_philo	*next;
	pthread_t		th;
	pthread_mutex_t	own_fork;
	struct s_admin	*adm;
	int				nb_eat;
}	t_philo;

typedef struct s_admin
{
	int				nb_philo;
	int				tt_d;
	int				tt_e;
	int				tt_s;
	int				nb_meal;
	t_philo			*philo;
	int				is_end;
	long int		start_time;
	int				eat_ok;
}	t_admin;

//main
void		pl_check_end(t_philo *philo);
void		pl_end_dead(t_philo philo);
void		pl_end_eat(t_philo *philo);
void		print_philo_piz(t_admin *admin);

//pl_parsing
int			pl_parsing(int argc, char **argv, t_admin *admin);
int			pl_check_argc(int argc);
int			pl_parse_argv(char **argv, t_admin *admin);
int			pl_check_argv(char **argv);
int			pl_has_digit(char **argv);

//pl_routine
void		*func(void *admin);
void		philo_eat(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

//pl_init
int			pl_init_piz(t_admin *admin);
void		pl_set(t_admin *admin);
void		pl_set_one_philo(t_admin *admin);

//pl_set_time
long int	pl_get_ms_time(void);
long int	pl_get_tenth_time(void);
long int	pl_get_now(t_admin *admin);
void		pl_msleep(long int time);
void		pl_tenth_sleep(long int time);

//pl_utils
int			pl_atoi(const char *nptr);
int			pl_isdigit(int c);
void		pl_free_all_piz(t_admin *admin);
void		pl_free_all(t_admin *admin);

#endif