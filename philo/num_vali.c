/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   num_vali.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dagabrie <dagabrie@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/24 17:39:36 by dagabrie          #+#    #+#             */
/*   Updated: 2023/08/25 13:43:44 by dagabrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int     nullstr(char **argv, int num)
{
        int     j;

        j = 1;
        while (j < num)
        {
                if (argv[j][0] == '\0')
                {
                        write (2, "Error\n", 7);
                        return (0);
                }
                j++;
        }
        return (1);
}

int     sinlcheck(char **argv, int num)
{
        int     j;

        j = 1;
        while (j < num)
        {
                if (1 == ft_startsign (argv[j][0]))
                {
                        if (0 == ft_isdigit (argv[j][1]))
                        {
                                write (2, "Error\n", 7);
                                return (0);
                        }
                }
                else if (0 == ft_isdigit(argv[j][0]))
                {
                        write (2, "Error\n", 7);
                        return (0);
                }
                j++;
        }
        return (1);
}

int     frt_isdigit(char **argv, int num)
{
        int     j;
        int     i;

        j = 1;
        i = 1;
        while (j < num)
        {
                while (argv[j][i])
                {
                        if (0 == ft_isdigit(argv[j][i]))
                        {
                                write (2, "Error\n", 7);
                                return (0);
                        }
                        i++;
                }
                i = 1;
                j++;
        }
        return (1);
}

int     max_min_int(char **argv, int num)
{
        int     j;

        j = 1;
        while (j < num)
        {
                if (2147483647 < ft_atoi(argv[j]) || 0 > ft_atoi(argv[j]))
                {
                        write (2, "Error\n", 7);
                        return (0);
                }
                j++;
        }
        return (1);
}

int     validacion(int argc, char **argv)
{
        if (argc < 2)
                return (0);
        if (0 == nullstr(argv, argc))
                return (0);
        if (0 == sinlcheck(argv, argc))
                return (0);
        if (0 == frt_isdigit(argv, argc))
                return (0);
        if (0 == max_min_int(argv, argc))
                return (0);
        return (1);
}