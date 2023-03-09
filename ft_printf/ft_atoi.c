/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 19:39:49 by grobert           #+#    #+#             */
/*   Updated: 2023/03/09 19:56:26 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int      ft_isspace(char c)
{
    if (c == ' ' || c == '\t' || c == '\v'
            || c == '\r' || c == '\f' || c == '\n')
            return (1);
    return (0);
}

int     ft_atoi(const char *str)
{
    int     res;
    int     sign;
    int     i;

    i = 0;
    sign = 1;
    res = 0;
    while (ft_isspace(str[i]))
        i++;
    if (str[i] == '-')
    {
        sign = -1;
        i++;
    }
    else if (str[i] == '+')
        i++;
    while (str[i] >= '0' && str[i] <= '9')
            res = (res * 10) + (str[i++] - '0');
    return (res * sign);
}