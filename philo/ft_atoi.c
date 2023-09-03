/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:43:05 by dagabrie          #+#    #+#             */
/*   Updated: 2023/09/03 19:18:08 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     ft_isdigit(int character)
{
        if (character < '0' || character > '9')
                return (0);
        return (1);
}

char    is_space(char character)
{
        return (character == '\t' || character == '\n'
                || character == '\v' || character == '\f'
                || character == '\r' || character == ' ');
}

int     ft_atoi(const char *string)
{
        int     nunber;
        int     count;
        int     negative;

        nunber = 0;
        count = 0;
        while (is_space(string[count]) == 1)
                count++;
        if (string[count] == '-' || string[count] == '+')
        {
                if (string[count] == '-')
                        negative = 1;
                count++;
        }
        while (ft_isdigit(string[count]) == 1)
        {
                nunber = nunber * 10 + string[count] - 48;
                count++;
        }
        if (negative == 1)
                return (nunber * -1);
        return (nunber);
}