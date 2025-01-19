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

# define PHILO_MAX 200
# define TIME_MAX 600

# define SUCCESS 0
# define ERROR 1

////////////////////////////STRUCTS//////////////////////////////
typedef struct s_philo
{
	int				id;
	uint64_t		last_meal;
	pthread_t		philo_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	right_fork;
	int				fork_id;
	int				meals_eaten;
	bool			is_dead;
	struct s_data	*data;
}					t_philo;

typedef struct s_data
{
	int				num_of_philos;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				meals_eaten_max;
	bool			philo_all_full;
	uint64_t		start_time;
	t_philo			*philos;
	pthread_t		monitor_thread;
	pthread_mutex_t	sync_mutex;
	pthread_mutex_t	print_mutex;
	bool			thread_ended;
	bool			print_allowed;
}					t_data;


////////////////////////////INCLUDES//////////////////////////////

////////////////////////////CHECKS//////////////////////////////

int					check_args(int argc, char **argv);
bool				ft_args_are_numbers(char *argv);

////////////////////////////MONITOR//////////////////////////////
bool	philosopher_dead(t_philo *philo, int time_to_die);
bool	verif_dead(t_philo *philos);
bool	verif_everyone_ate(t_philo *philos);
void	*monitor(void *arg);

////////////////////////////ROUTINE//////////////////////////////

void				*routine(void *arg);

////////////////////////////UTILS//////////////////////////////
long				ft_atol(const char *str);
int					ft_isdigit(int c);
void				print_message(char *str, t_philo *philo);
uint64_t			get_time(void);
// int					ft_usleep(t_philo *philo, int timer);
int					ft_usleep(size_t time);

////////////////////////////INIT//////////////////////////////
void				initializing(t_data *data, char **argv, int argc);
void				lst_clear_philo(t_data *data);
void				print_tab(t_data *data);

////////////////////////////FREE//////////////////////////////
void				exit_error(t_data *data, char *msg);
void				ft_free_all(t_data *data);

#endif