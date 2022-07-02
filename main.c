#include "philo.h"
unsigned long	get_time(void)
{
    struct timeval	time;
    unsigned long	now;

    gettimeofday(&time, NULL);
    now = time.tv_sec * 1000 + time.tv_usec / 1000;
    return (now);
}
void ft_usleep(long time)
{
    struct timeval now;
    struct timeval start;
    gettimeofday(&start, 0);
    gettimeofday(&now, 0);
    while ((now.tv_sec - start.tv_sec) * 1000 + (now.tv_usec - start.tv_usec) / 1000 < time)
    {
        usleep(10);
        gettimeofday(&now, 0);
    }
}

void fill_params(t_params *params, char **argv, int argc)
{
    params->num_phil = ft_atoi(argv[1]);
    params->time_die = ft_atoi(argv[2]);
    params->time_eat = ft_atoi(argv[3]);
    params->time_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        params->num_phil_must_eat = ft_atoi(argv[5]);
    else
        params->num_phil_must_eat = -1;

}
void philo_print(t_philo *philo, char *text)
{
    pthread_mutex_lock(&philo -> params -> print_mut);
    pthread_mutex_lock(&philo -> params -> close_check_mut);
    if (philo -> params -> is_end <= 0)
    {
        pthread_mutex_unlock(&philo -> params -> print_mut);
        pthread_mutex_unlock(&philo -> params -> close_check_mut);
        return ;
    }
    printf("%lu %d %s \n", get_time() - philo -> params -> start, philo -> id, text);
    pthread_mutex_unlock(&philo -> params -> print_mut);
    pthread_mutex_unlock(&philo -> params -> close_check_mut);
}

void try_eat(t_philo *philo, int time_eat)
{
    pthread_mutex_lock(philo -> left);
    philo_print(philo, "has taken a fork");
    pthread_mutex_lock(philo -> right);
    philo_print(philo, "has taken a fork");
    philo_print(philo, "is eating");
    pthread_mutex_lock(&philo -> params -> eat_check_mut);
    philo -> eat_time = get_time();
    pthread_mutex_unlock(&philo -> params -> eat_check_mut);
    ft_usleep(time_eat);
    pthread_mutex_unlock(philo -> left);
    pthread_mutex_unlock(philo -> right);
    philo -> eat_num--;
}
void philo_cycle(t_philo *philo, int time_eat, int time_sleep)
{
    while (1)
    {
        pthread_mutex_lock(&philo -> params -> close_check_mut);
        if (philo -> params -> is_end <= 0)
        {
            pthread_mutex_unlock(&(philo -> params -> close_check_mut));
            break;
        }
        pthread_mutex_unlock(&(philo -> params -> close_check_mut));
        try_eat(philo, time_eat);
        pthread_mutex_lock(&(philo -> params -> close_check_mut));
        if (philo -> eat_num == 0)
            philo -> eat_over = 1;
        pthread_mutex_unlock(&(philo -> params -> close_check_mut));
        philo_print(philo, "is sleeping");
        ft_usleep(time_sleep);
        philo_print(philo, "is thinking");
    }
}
void *philo_thread(void *v_philo)
{
    printf("huy");
    t_philo *philo;
    int time_eat;
    int time_sleep;

    philo = (t_philo *)v_philo;
    time_eat = philo-> params -> time_eat;
    time_sleep = philo -> params -> time_sleep;
    philo_print(philo, "Думает");
    if (philo -> id % 2 == 0 && philo -> params -> num_phil != 1)
        ft_usleep(time_sleep - 10);
    if (philo -> params -> num_phil == 1)
    {
        philo_print(philo, "Взял вилку");
        ft_usleep(philo -> params -> time_die);
    }
    else
        philo_cycle(philo, time_eat, time_sleep);
    return(0);


}
int pthread_manage(t_params *params, int command)
{
    int i;

    i = 0;
    if (command == 0)
    {
        while (i < params->num_phil)
        {
            pthread_join(params->life[i], NULL);
            i++;
        }
    }
        if (command == 1)
        {
            params -> start = get_time();
            while (i < params -> num_phil)
            {
                params -> philo[i].eat_time = params -> start;
                if (pthread_create(&(params -> life[i]),
                                   NULL, philo_thread, &(params -> philo[i])))
                    return(1);
                i++;
            }
        }
    return(0);

}
int main(int argc, char **argv)
{
    t_params params;
    if (argc != 5 && argc != 6)
    {
        printf("%s","error1");
        return(0);
    }
    fill_params(&params, argv, argc);
    if (init_params(&params))
    {
        printf("%s", "error2");
        return(0);
    }
    if(pthread_manage(&params, 1))
    {
        printf("error3");
        return(0);
    }
    pthread_watch(&params);
    pthread_manage(&params, 0);

    return(0);
}