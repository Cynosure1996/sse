#include "philo.h"
void	check_philo_eat_num(t_params *params, int i)
{
    pthread_mutex_lock(&params->close_check_mut);
    while (i < params->num_phil)
    {
        if (params->is_end <= 0)
        {
            pthread_mutex_unlock(&params->close_check_mut);
            break ;
        }
        if (!params->philo[i].eat_over)
        {
            break ;
        }
        i++;
    }
    if (i == params->num_phil)
    {
        params->is_end = 0;
    }
    pthread_mutex_unlock(&params->close_check_mut);
}
void	check_philo_time(t_params *params, int i)
{
    while (i < params->num_phil)
    {
        pthread_mutex_lock(&params->close_check_mut);
        if (params->is_end <= 0)
        {
            pthread_mutex_unlock(&params->close_check_mut);
            break ;
        }
        pthread_mutex_unlock(&params->close_check_mut);
        pthread_mutex_lock(&params->eat_check_mut);
        if (get_time() - params->philo[i].eat_time
            >= (unsigned long)params->time_die)
        {
            pthread_mutex_lock(&params->close_check_mut);
            params->is_end = 0;
            pthread_mutex_unlock(&params->close_check_mut);
            printf("%lu %d died\n",
                   get_time() - params->start, i + 1);
        }
        i++;
        pthread_mutex_unlock(&params->eat_check_mut);
    }
}

void pthread_watch(t_params *params)
{
    while(1)
    {
        pthread_mutex_lock(&params -> close_check_mut);
        if (params -> is_end <= 0) {
            pthread_mutex_unlock(&params->close_check_mut);
            break;
        }
        pthread_mutex_unlock(&params->close_check_mut);
        check_philo_time(params, 0);
        check_philo_eat_num(params, 0);
        pthread_mutex_unlock(&params->close_check_mut);
        usleep(5000);

    }
}