/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:58:23 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 05:40:40 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

//// PROTOTYPES ////

void	got_sig(int sig);

int		send_byte(int pid, char c);

int		check_args(int argc, char **argv);

//// GLOBAL VAR ////

int	g_status;

//// FUNCTIONS ////

int	main(int argc, char **argv)
{
	int		pid_srv;
	int		msg_cnt;
	int		msg_len;
	char	act_chr;

	pid_srv = check_args(argc, argv);
	if (pid_srv < 0)
		return (-1);
	msg_cnt = 0;
	msg_len = ft_strlen(argv[2]);
	signal(10, &got_sig);
	if (send_byte(pid_srv, 2))
	{
		ft_printf("Server did not respond :( .\n");
		return (-1);
	}
	while (msg_cnt < msg_len)
	{
		act_chr = *(argv[2] + msg_cnt);
		send_byte(pid_srv, act_chr);
		msg_cnt = msg_cnt + 1;
	}
	send_byte(pid_srv, 3);
	return (0);
}

void	got_sig(int sig)
{
	g_status = (sig != 0);
}

int	send_byte(int pid, char c)
{
	int	i;
	int	mask;

	i = 0;
	mask = 0b10000000;
	while (i < 8)
	{
		g_status = 0;
		if (c & mask)
			kill(pid, 10);
		else
			kill(pid, 12);
		sleep(1);
		if (!g_status)
			return (1);
		i = i + 1;
		mask = mask >> 1;
	}
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	pid_srv;

	if (argc != 3)
	{
		ft_printf("Wrong no. of arguments!\n\
			Usage: client [server pid] [message]\n");
		return (-1);
	}
	pid_srv = ft_atoi(argv[1]);
	if (!pid_srv)
	{
		ft_printf("First argument must be the server pid.\n");
		return (-1);
	}
	if (!ft_strncmp("", argv[2], 1))
	{
		ft_printf("Second argument can not be an empty string.\n");
		return (-1);
	}
	return (pid_srv);
}
