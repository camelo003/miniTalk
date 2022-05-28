/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_int.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 03:44:37 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 01:39:06 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_digit(long i);

int	ft_solve_int(long i)
{
	int	r;

	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	if (i == -9223372036854775807)
	{
		write(1, "-9223372036854775807", 20);
		return (20);
	}
	if (i < 0)
	{
		i = i * -1;
		r = 1;
		write(1, "-", 1);
	}
	else
		r = 0;
	return (r + write_digit(i));
}

static int	write_digit(long i)
{
	char	c;
	int		r;

	c = '0' + (i % 10);
	r = 0;
	if (i > 0)
	{
		r = 1 + write_digit(i / 10);
		write(1, &c, 1);
	}
	return (r);
}
