/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:11:33 by dagabrie          #+#    #+#             */
/*   Updated: 2023/09/03 20:28:18 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_chair *db_chair(void)
{
    static t_chair *data;
    return(&data);
}

t_table *db_table(void)
{
    static t_table *data;
    return(&data);
}