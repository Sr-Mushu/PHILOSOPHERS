/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anlima <anlima@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2023/08/29 18:28:47 by dagabrie         ###   ########.fr       */
=======
/*   Updated: 2023/08/28 20:43:49 by anlima           ###   ########.fr       */
>>>>>>> de71a01a1a8106b0609810a758ba6b8f83ea5656
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

<<<<<<< HEAD
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
=======
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
>>>>>>> de71a01a1a8106b0609810a758ba6b8f83ea5656
	}
	return (0);
}

void	create_thread(pthread_t *threads)
{
	int	i;
<<<<<<< HEAD

	i = 0;
	while (i <= 4)
	{
		pthread_create(&threads[i], NULL, routine, NULL);
=======
	int	id_values[4];

	i = 0;
	while (i < 4)
	{
		id_values[i] = i;
		usleep(500);
		pthread_create(&threads[i], NULL, routine, &id_values[i]);
>>>>>>> de71a01a1a8106b0609810a758ba6b8f83ea5656
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
<<<<<<< HEAD
	while (id <= 4)
		pthread_join(threads[id++], NULL);
}
=======
	while (id < 4)
		pthread_join(threads[id++], NULL);
}
>>>>>>> de71a01a1a8106b0609810a758ba6b8f83ea5656
