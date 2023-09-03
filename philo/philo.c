/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 16:40:01 by dagabrie          #+#    #+#             */
/*   Updated: 2023/09/03 20:28:47 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

// Start time , End time.
// Reurn time difrece.

long	imer(void)
{
	struct timeval	val;

	gettimeofday(&val, 0);
	return (val.tv_sec * 1000000L + val.tv_usec);
}

// argv 1 number_of_philosophers 
// argv 2 time_to_die time_to_eat
// argv 3 time_to_sleep
// argv 4 number_of_times_each_philosopher_must_eat (Opecional.)
int	main(int argc,char **argv)
{
	t_table	*table;

	table = db_table();
	table = (t_table *)malloc(sizeof(t_table));
	if (!table)
		exit_philo();
	if (argc < 5 || argc > 6)
		return (exit_philo());
	if (init_philo(table, argv) != 0)
		return (exit_philo());
	if (set_table(table) != 0)
		return (exit_philo());
	if (start_dinner(table) != 0)
		return (exit_message());
	return (exit_philo());
}