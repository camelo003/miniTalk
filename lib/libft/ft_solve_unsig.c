/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_unsig.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 04:09:54 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 01:40:07 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_digit(unsigned long i);

int	ft_solve_unsig(unsigned long i)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (write_digit(i));
}

static int	write_digit(unsigned long i)
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
