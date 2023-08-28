/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/25 19:15:27 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


void	*rotina1(void *p)
{
	t_thread	*arg;

	arg = (t_thread *)p;
	pthread_mutex_lock(arg->mutex);
	printf("Nome:%i, Num: %i\n", arg->name, (++*arg->num));
	pthread_mutex_unlock(arg->mutex);
    return (0);
}

void creat_thread()
{
	
}

int main(int argc,char **argv){
    
	pthread_t		thread;
	int				j;
	pthread_mutex_t	i;
	t_public_data		p_data;

	


	int				j;
	pthread_mutex_t	i;
	t_thread		p_thread1;
	t_thread		p_thread2;

	j = 5;
	pthread_mutex_init(&i, NULL);
	p_thread1.num = &j;
    p_thread1.name = 1;
    p_thread1.mutex = &i;
    p_thread2.num = &j;
    p_thread2.name = 2;
    p_thread2.mutex = &i;
	pthread_create(&thread1, NULL, &rotina1, (void *)&p_thread1);
	pthread_create(&thread2, NULL, &rotina1, (void *)&p_thread2);
	pthread_join(thread1, 0);
	pthread_join(thread2, 0);
	return (0);

	
	if(validacion(argc,argv))
		printf("ok\n");
	else
		printf("ko\n");
}