/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_ptr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 02:16:54 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 01:38:10 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_hex(unsigned long n, char c);

static char	get_hex_digit(int d);

int	ft_solve_ptr(long unsigned p, t_fmt fmt)
{
	int	prfx;

	if (p == 0)
	{
		write(1, "0x0", 3);
		return (3);
	}
	write(1, "0x", 2);
	prfx = 2;
	return (prfx + write_hex(p, fmt.type));
}

static int	write_hex(unsigned long n, char t)
{
	char	c;
	int		r;

	c = get_hex_digit(n % 16);
	r = 0;
	if (n > 0)
	{
		r = 1 + write_hex(n / 16, t);
		write(1, &c, 1);
	}
	return (r);
}

static char	get_hex_digit(int d)
{
	char	*base;

	base = "0123456789abcdef";
	return (base[d % 16]);
}
