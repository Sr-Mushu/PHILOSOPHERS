/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/29 18:28:47 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *ok)
{
	int	i;
	
	ok++;
	i = 0;
	while (i < 5)
	{
		pthread_mutex_lock(public_data()->access);
		printf("hi is : x vez : %d\n", i);
		i++;
		pthread_mutex_unlock(public_data()->access);
	}
	return (0);
}

void	create_thread(pthread_t *threads)
{
	int	i;

	i = 0;
	while (i <= 4)
	{
		pthread_create(&threads[i], NULL, routine, NULL);
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
	while (id <= 4)
		pthread_join(threads[id++], NULL);
}