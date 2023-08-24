/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:39 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/24 20:36:10 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data
{
	long			eat;
    long			think;
	long			sleep;
}	                t_data;

// ft_atoi.c
int 	ft_atoi(const char *string);

//ft_utiliti.c
int     ft_isdigit(int character);
int		ft_startsign(int character);

// static_data.c
t_data *data(void);

// num_vali.c
int     validacion(int numb_arg, char **arg);
#endif