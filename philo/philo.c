/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/28 20:03:49 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*routine(void *idv)
{
	int *iddv=idv;
	int id = *iddv;
	int i = 0;
	while (i < 5)
	{
	pthread_mutex_lock(data()->mutex);
	i++;
	printf("hi is : %d vez : %d\n",id, 1);
	pthread_mutex_unlock(data()->mutex);
	sleep(1);
	}
	return(0);
}

void create_thread()
{
	pthread_t thread;
	int id = 0;
	while (id < 4)
	{
		id++;
		pthread_create(&thread,NULL,routine,&id);
	}
	pthread_join(thread,NULL);
	
	
}

int main(void)
{
	pthread_mutex_t	i;
	data()->mutex = &i;
	pthread_mutex_init(&i, NULL);
	create_thread();
	
    /*if(3 == argc || 4 == argc)
	{
		
	}*/
}