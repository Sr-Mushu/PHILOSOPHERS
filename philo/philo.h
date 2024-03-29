/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:39 by dagabrie          #+#    #+#             */
/*   Updated: 2023/09/04 14:04:51 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/wait.h>
# include <sys/time.h>
# include <stdbool.h>
# include <pthread.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>



typedef struct s_chair
{
	pthread_t			philo;
	int					id;
	int					must_eat;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	long long			time_started;
	long long			time_eated;
	bool				*l_f_taken;
	bool				*r_f_taken;
	bool				*dead;
	bool				*finish_dinner;
	pthread_mutex_t		*left_fork;
	pthread_mutex_t		*right_fork;
	pthread_mutex_t		*message;
	pthread_mutex_t		*time;
	pthread_mutex_t		*death;
	pthread_mutex_t		*all_eat;
}	t_chair;

typedef struct s_table
{
	int					philo_number;
	int					must_eat;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	long long			time_started;
	bool				opt_arg;
	bool				thread_dead;
	bool				finish_dinner;
	bool				*f_taken;
	t_chair				*chair;
	pthread_mutex_t		*forks;
	pthread_mutex_t		message;
	pthread_mutex_t		time;
	pthread_mutex_t		death;
	pthread_mutex_t		all_eat;
}	t_table;


//================={philos}=======================//


void			*dinner(void);

bool			end_dinner(void);

void			philo_sleep(void); 

//
void			arrange_table(void);

// supervise if to long since the last meal
// if is to long "kill" the philo.
void			*supervise_eat(void);

// supervise if the philo died
// stop iniciate the "stop dinner" iniciate the end.
void			*supervise_death(void);

// error handiling 
int				exit_message(void);

// is going to all free memory and stop programe. 
int				exit_philo(void);


//================={data}=========================//

//returns a static variable t_table address;
t_table					*db_table(void);

//================={utiliti}======================//


// ft_utiliti.c

int						ft_atoi(const char *string);
int						ft_isdigit(int character);
int						ft_startsign(int character);

// num_vali.c

int						validacion(int numb_arg, char **arg);

#endif
