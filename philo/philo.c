/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/31 15:18:25 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *x)
{
	x++;
	t_public_data	data;

	
	pthread_mutex_lock(public_data()->access);
	data.id = public_data()->id++;
	data.eat = public_data()->eat;
	data.sleep = public_data()->sleep;
	data.think = public_data()->think;
	pthread_mutex_unlock(public_data()->access);
	while (1)
	{
		pthread_mutex_lock(public_data()->access);
		printf("eating %d \n",data.id);
		sleep(data.eat);
		pthread_mutex_unlock(public_data()->access);
		printf("sleeping %d \n",data.id);
		sleep(data.sleep);
		printf("thinking %d \n",data.id);
		sleep(data.think);
	}
	return (0);
}

void	create_thread(pthread_t *threads,int num)
{
	int	i;

	i = 0;
	while (i <= num)
	{
		pthread_create(&threads[i], NULL, routine, NULL);
		i++;
	}
}

int	main(int argc,char **argv)
{
	pthread_mutex_t	i;
	pthread_t		*threads;
	int				id;

	argc++;
	public_data()->eat = atoi(argv[2]);
	public_data()->sleep = atoi(argv[3]);
	public_data()->think = atoi(argv[4]);
	public_data()->access = &i;
	pthread_mutex_init(&i, NULL);
	threads = (pthread_t *)malloc(sizeof(pthread_t) * atoi(argv[1]));
	
	create_thread(threads,atoi(argv[1]));
	id = 0;
	while (id <= atoi(argv[1]))
		pthread_join(threads[id++], NULL);
}
