/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   static_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:11:33 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/29 17:22:14 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

t_public_data *public_data(void)
{
    static t_public_data data;
    return(&data);
}

t_private_data *private_data(void)
{
    static t_private_data data;
    return(&data);
}