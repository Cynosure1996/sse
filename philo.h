#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct s_philo{
    unsigned  long long timer;
    unsigned int count_eat;
    unsigned int count_over;
    pthread_mutex_t *left;
    pthread_mutex_t *right;
    int eat_num;
    int id;
    int eat_over;
    unsigned int eat_time;
    struct s_params *params;

}t_philo;
typedef struct s_params{
    pthread_t *life;
    pthread_mutex_t print_mut;
    pthread_mutex_t	*fork;
    pthread_mutex_t eat_check_mut;
    pthread_mutex_t close_check_mut;
    int num_phil;
    int time_die;
    int time_eat;
    int time_sleep;
    int num_phil_must_eat;
    int is_end;
    t_philo *philo;
    unsigned long start;
}t_params;

int     ft_isdigit(int c);
int	    ft_atoi(const char *str);
void    fill_params(t_params *params, char **argv);
void    init_philo(t_params *params);
int     init_params (t_params *params);
unsigned long	get_time(void);
void ft_usleep(long time);
void fill_params(t_params *params, char **argv);
void philo_print(t_philo *philo, char *text);
void try_eat(t_philo *philo, int time_eat);
void philo_cycle(t_philo *philo, int time_eat, int time_sleep);
void *philo_thread(void *v_philo);
int pthread_manage(t_params *params, int command);
void	check_philo_eat_num(t_params *params, int i);
void	check_philo_time(t_params *params, int i);
void pthread_watch(t_params *params);
#endif