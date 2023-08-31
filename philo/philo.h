/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:39 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/29 20:58:47 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_public_data
{
	int			id;
	int			eat;
	int			think;
	int			sleep;
	pthread_mutex_t	*access;
}				t_public_data;


typedef struct s_private_data
{
	pthread_mutex_t	*access;
}				t_private_data;

// ft_atoi.c
int				ft_atoi(const char *string);

// ft_utiliti.c
int				ft_isdigit(int character);
int				ft_startsign(int character);

// static_data.c
t_public_data	*public_data(void);
t_private_data	*private_data(void);

// num_vali.c
int				validacion(int numb_arg, char **arg);
#endif