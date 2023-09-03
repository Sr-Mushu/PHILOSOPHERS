/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utiliti.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 20:33:52 by dagabrie          #+#    #+#             */
/*   Updated: 2023/09/03 20:22:08 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_startsign(int c)
{
	if (c == '-' || c == '+')
		return (1);
	return (0);
}

int     ft_isdigit(int c)
{
        if (c < '0' || c > '9')
                return (0);
        return (1);
}

char    is_space(char c)
{
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	if (c == ' ')
		return (1);
	else
		return (0);
}

int     ft_atoi(const char *str)
{
        int     num;
        int     i;
        int     flag;

        num = 0;
        i = 0;
        while (is_space(str[i]) == 1)
                i++;
        if (str[i] == '-' || str[i] == '+')
        {
                if (str[i] == '-')
                        flag = 1;
                i++;
        }
        while (ft_isdigit(str[i]) == 1)
        {
                num = num * 10 + str[i] - 48;
                i++;
        }
        if (flag == 1)
                return (num * -1);
        return (num);
}
