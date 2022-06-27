#include "philo.h"

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
void init_philo(t_params *params)
{
    int i;

    i = 0;
    while (i < params -> num_phil)
    {
        params -> philo[i].eat_over = 0;
        params -> philo[i].eat_time = 0;
        params -> philo[i].id = i + 1;
        params -> philo[i].right = &params -> fork[i];
        params -> philo[i].left = &params -> fork[(i + 1) % params -> num_phil];
    }
}
int init_params (t_params *params)
{
    int i;
    int chk;

    i = 0;
    chk = pthread_mutex_init(&(params -> eat_check_mut), NULL);
    chk += pthread_mutex_init(&(params -> close_check_mut), NULL);
    chk += pthread_mutex_init(&(params -> print_mut), NULL);
    params -> philo = NULL;
    params -> fork = NULL;
    params -> philo = malloc(sizeof(t_philo) * params -> num_phil);
    params -> fork = malloc(sizeof (pthread_mutex_t) * params -> num_phil);
    params -> life = malloc(sizeof (pthread_t) * params -> num_phil);
    if (!params -> philo | !params -> fork | !params -> life)
        return(1);
    while (i < params -> num_phil)
    {
        chk += pthread_mutex_init(&params -> fork[i], NULL);
        i++;
    }
    return (chk);

}
void fill_params(t_params *params, char **argv)
{
    params->num_phil = ft_atoi(argv[1]);
    params->time_die = ft_atoi(argv[2]);
    params->time_eat = ft_atoi(argv[3]);
    params->time_sleep = ft_atoi(argv[4]);
    params->num_phil_must_eat = ft_atoi(argv[5]);

}

void *test(void *data)
{
    int *num = data;
    while(*num < 1000)
        *(num)++;
    return(0);
}
int main(int argc, char **argv)
{
    if (argc != 5 && argc != 6)
    {
        printf("%s","error");
        return(0);
    }
    pthread_t id;
    int tmp;
    pthread_create(&id,0,test,&tmp);
    while (tmp < 1000)
        printf ("%d", tmp);
    pthread_join(id, 0);
    argc++;
    t_params params;
    fill_params(&params, argv);
    return(0);
}