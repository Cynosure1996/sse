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
    int id;
    unsigned int eat_over;
    unsigned int eat_time;

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
    t_philo *philo;
}t_params;

int	ft_isdigit(int c);
int	ft_atoi(const char *str);
void fill_params(t_params *params, char **argv);

#endif