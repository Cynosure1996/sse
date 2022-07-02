#include "philo.h"
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