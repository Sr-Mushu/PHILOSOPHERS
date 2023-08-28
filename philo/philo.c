/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/28 20:43:49 by anlima           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *id_ptr)
{
	int	i;
	int	*id;

	id = (int *)id_ptr;
	i = 0;
	while (i < 5)
	{
		pthread_mutex_lock(data()->mutex);
		printf("hi is : %d vez : %d\n", *id, i);
		usleep(100);
		i++;
		pthread_mutex_unlock(data()->mutex);
	}
	return (0);
}

void	create_thread(pthread_t *threads)
{
	int	i;
	int	id_values[4];

	i = 0;
	while (i < 4)
	{
		id_values[i] = i;
		usleep(500);
		pthread_create(&threads[i], NULL, routine, &id_values[i]);
		i++;
	}
}

int	main(void)
{
	pthread_mutex_t	i;
	pthread_t		*threads;
	int				id;

	data()->mutex = &i;
	pthread_mutex_init(&i, NULL);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * 4);
	create_thread(threads);
	id = 0;
	while (id < 4)
		pthread_join(threads[id++], NULL);
}
