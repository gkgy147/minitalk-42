/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_client.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: grobert <grobert@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/09 17:36:37 by grobert           #+#    #+#             */
/*   Updated: 2023/03/09 20:58:54 by grobert          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_minitalk.h"

void    signal_error(void)
{
    ft_printf("\n%sclient: unexpected error.%s\n", RED, END);
    exit(EXIT_FAILURE);
}

void    char_to_bin(unsigned char c, int pid)
{
    int     bit;

    bit = 0;
    while(bit < 8)
    {
        if (c & 128)
        {
            if (kill(pid, SIGUSR2) == -1)
                signal_error();
        }
        else
        {
            if (kill(pid, SIGUSR1) == -1)
                signal_error();
        }
        c <<= 1;
        bit++;
        pause();
        usleep(100);
    }
}

void    sent_text(char *str, int pid)
{
    int     i;

    i = 0;
    while (str[i])
        char_to_bin(str[i++], pid);
    char_to_bin('\0', pid);
}

void    received(int sig)
{
    static  int     sent;

    if (sig == SIGUSR1)
    {
        ft_printf("%s%d signal sent successfully!%s\n", GREEN, ++sent, END);
        exit(EXIT_SUCCESS);
    }
    if (sig == SIGUSR2)
        ++sent;
}

int     main(int ac, char **av)
{
    int     server_pid;
    int     client_pid;

    client_pid = getpid();
    if (ac == 3)
    {
        ft_printf("%sclient pid: %d%s\n", RED, client_pid, END);
        signal(SIGUSR1, received);
        signal(SIGUSR2, received);
        server_pid = ft_atoi(av[1]);
        ft_printf("%sText currently sending....%s\n", YELLOW, END);
        sent_text(av[2], server_pid);
    }
    else
            ft_printf("%sformat: ./client <server_pid> <text you want to send>%s\n", RED, END);
    return (EXIT_FAILURE);
}