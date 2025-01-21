/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rbalazs <rbalazs@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/21 12:44:18 by rbalazs           #+#    #+#             */
/*   Updated: 2025/01/21 13:36:26 by rbalazs          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdint.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

////////////////////////////STRUCTS//////////////////////////////
typedef struct s_philo
{
	int				id;
	uint64_t		last_meal;
	pthread_t		philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	int				meals_eaten;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_eaten_max;
	uint64_t		start_time;
	t_philo			*philos;
	pthread_mutex_t	global_mutex;
	bool			is_dead;
}					t_data;

////////////////////////////INCLUDES//////////////////////////////

////////////////////////////CHECKS//////////////////////////////

bool				check_args(int argc, char **argv);
bool				ft_args_are_numbers(char *argv);

////////////////////////////MONITOR//////////////////////////////
bool				check_and_print_death(t_philo *philos);
bool				verif_everyone_ate(t_philo *philos);
void				*monitor(void *arg);

////////////////////////////ROUTINE//////////////////////////////

bool				verif_isdead(t_philo *philo);
void				*routine(void *arg);

////////////////////////////UTILS//////////////////////////////
long				ft_atol(const char *str);
int					ft_isdigit(int c);
void				print_message(char *str, t_philo *philo);
uint64_t			get_time(void);
int					ft_usleep(size_t time);

////////////////////////////INIT//////////////////////////////
bool				initializing(t_data *data, char **argv, int argc);
void				lst_clear_philo(t_data *data);
void				print_tab(t_data *data);

////////////////////////////FREE//////////////////////////////
void				ft_free_all(t_data *data);

#endif