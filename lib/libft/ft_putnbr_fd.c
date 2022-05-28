/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:09:37 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:09:38 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	dec_cases(int n)
{
	unsigned int	i;
	int				local_n;

	i = 0;
	if (n < 0)
		local_n = -n;
	else
		local_n = n;
	while (local_n != 0)
	{
		local_n = local_n / 10;
		i = i + 1;
	}
	return (i);
}

static void	fill_int_string(int n, int fd, int cases)
{
	int				i;
	unsigned int	act_case;

	i = 0;
	act_case = 1;
	while (i < cases - 1)
	{
		act_case = act_case * 10;
		i = i + 1;
	}
	while (act_case >= 1)
	{
		ft_putchar_fd(n / act_case + '0', fd);
		n = n - act_case * (n / act_case);
		act_case = act_case / 10;
	}
}

void	ft_putnbr_fd(int n, int fd)
{
	if (n == 0)
		ft_putchar_fd('0', fd);
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = -n;
		}
		fill_int_string(n, fd, dec_cases(n));
	}
}
