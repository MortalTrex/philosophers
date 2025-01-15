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

// typedef struct s_philo
// {
// 	pthread_t			tid;
// 	int					id;

// 	size_t				last_meal;
// 	size_t				meals_eaten;
// 	size_t				time_to_die;
// 	size_t				time_to_eat;
// 	size_t				time_to_sleep;

// 	pthread_mutex_t		last_meal_mutex;
// 	pthread_mutex_t		meals_eaten_mutex;
// 	pthread_mutex_t		*fork_left;
// 	pthread_mutex_t		*fork_right;
// 	struct s_sync		*sync;
// 	struct s_philo		*next;
// 	struct s_philo		*prev;
// }						t_philo;

// typedef struct s_sync
// {
// 	pthread_mutex_t		start;
// 	pthread_mutex_t		death_lock;
// 	pthread_mutex_t		eat_lock;
// 	pthread_mutex_t		write_lock;
// 	//pthread_mutex_t	time_lock;
// 	bool				is_dead;
// 	bool				is_all_eaten;
// 	bool 				is_meals_eaten;
// 	bool				stop_routine;
// 	size_t				start_time;
// }						t_sync;

// typedef	struct s_philo_manage
// {
// 	t_philo				*head;
// 	t_philo				*current;
// 	size_t				size;
// }						t_philo_manag;

// typedef struct s_init
// {
// 	int					num_of_philos;
// 	int					time_to_live;
// 	int					time_to_eat;
// 	int					time_to_sleep;
// 	int					meals_eaten;
// }						t_init;

// typedef struct s_data
// {
// 	t_philo_manag		p_manag;
// 	t_sync				central;
// 	t_init				init;
// }					t_data;

////////////////////////////INCLUDES//////////////////////////////

////////////////////////////CHECKS//////////////////////////////

int					parsing(int argc, char **argv);
bool				ft_args_are_numbers(char *argv);

////////////////////////////ROUTINE//////////////////////////////

void				*routine(void *arg);

////////////////////////////UTILS//////////////////////////////
int					ft_atoi(const char *str);
void				ft_bzero(void *s, size_t n);
long				ft_atol(const char *str);
int					ft_isdigit(int c);
void				print_message(char *str, t_philo *philo, t_sync *sync);
uint64_t			get_time(void);
void				ft_free_all(t_data *data);

////////////////////////////INIT//////////////////////////////
void				init_input(t_data *data, char **argv);
int					initializing(t_data *data, char **argv);

void				add_philo(t_data *data, t_philo *new);
t_philo				*new_philo(t_data *data, int i);
void				lst_clear_philo(t_data *data);

void				g_print_lst(t_data *data);

#endif