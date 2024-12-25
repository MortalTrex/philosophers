#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define PHILO_MAX 300

////////////////////////////STRUCTS//////////////////////////////
typedef struct s_philo
{
	pthread_t		thread;
	int				id;
	int				eating;
	int				meals_eaten;
	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	size_t			start_time;
	size_t			num_of_philos;
	size_t			num_times_to_eat;
}					t_philo;
typedef struct s_data
{
	int				dead_flag;
	t_philo			*philos;
}					t_data;

////////////////////////////INCLUDES//////////////////////////////

////////////////////////////CHECKS//////////////////////////////

bool				verify_args(int argc, char **argv);
bool				ft_args_are_numbers(char *argv);

////////////////////////////UTILS//////////////////////////////
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);

////////////////////////////INIT//////////////////////////////
void 				init_input(t_philo *philo, char **argv);

#endif