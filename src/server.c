/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 05:45:39 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 06:47:21 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

//// PROTOTYPES ////

void	clear_lst(void *item);

void	check_eot(char c);

void	get_bit(int pid_cli, int sig_bit);

void	func_act(int sig, siginfo_t *info, void *ucontext);

//// GLOBAL VAR ////

t_list	*g_lst;

//// FUNCTIONS ////

int	main(void)
{
	struct sigaction	act;

	ft_memset(&act, '\0', sizeof(act));
	act.sa_sigaction = &func_act;
	act.sa_flags = SA_SIGINFO;
	sigaction(10, &act, 0);
	sigaction(12, &act, 0);
	sigemptyset(&act.sa_mask);
	ft_printf("\n");
	ft_printf("+-------------------------------------------+\n");
	ft_printf("|   Starting gcamelo-'s  minitalk server!   |\n");
	ft_printf("|   PID: %d                                |\n", getpid());
	ft_printf("+-------------------------------------------+\n\n");
	ft_printf("waiting for messages...\n\n");
	while (1)
		pause();
}

void	clear_lst(void *item)
{
	t_list	*act_lst;

	act_lst = (t_list *)item;
	free(act_lst->content);
	free(act_lst->next);
	free(act_lst);
}

void	check_eot(char c)
{
	t_list	*wrk_lst;
	char	*msg;
	int		cnt;

	if (c == 3)
	{
		msg = ft_calloc(ft_lstsize(g_lst), 1);
		wrk_lst = g_lst->next;
		cnt = 0;
		while (wrk_lst)
		{
			*(msg + cnt) = *(wrk_lst->content);
			if (*(msg + cnt) == 3)
				*(msg + cnt) = '\0';
			cnt = cnt + 1;
			wrk_lst = wrk_lst->next;
		}
		ft_printf("%s\n", msg);
		free(msg);
		ft_lstclear(&g_lst, &clear_lst);
	}
}

void	get_bit(int pid_cli, int sig_bit)
{
	static char	inn_cnt = 0;
	char		*ini_chr;
	int			mask;
	t_list		*wrk_lst;

	if (inn_cnt == 0)
	{
		ini_chr = ft_calloc(1, 1);
		*ini_chr = 0;
		if (ft_lstsize(g_lst) == 0)
			g_lst = ft_lstnew(ini_chr);
		else
			ft_lstadd_back(&g_lst, ft_lstnew(ini_chr));
	}
	wrk_lst = ft_lstlast(g_lst);
	mask = 0b10000000 >> inn_cnt;
	if (sig_bit)
		*(wrk_lst->content) = *(wrk_lst->content) | mask;
	if (inn_cnt == 7)
		check_eot(*(wrk_lst->content));
	inn_cnt = (inn_cnt + 1) % 8;
	kill(pid_cli, 10);
}

void	func_act(int sig, siginfo_t *info, void *ucontext)
{
	(void)ucontext;
	get_bit(info->si_pid, sig < 11);
}
