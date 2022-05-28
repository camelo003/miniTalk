/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/23 03:11:59 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 01:42:26 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	write_hex(unsigned int n, char c);

static char	get_hex_digit(int d, char c);

int	ft_solve_hex(unsigned int i, t_fmt fmt)
{
	if (i == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	return (write_hex(i, fmt.type));
}

static int	write_hex(unsigned int n, char t)
{
	char	c;
	int		r;

	c = get_hex_digit(n % 16, t);
	r = 0;
	if (n > 0)
	{
		r = 1 + write_hex(n / 16, t);
		write(1, &c, 1);
	}
	return (r);
}

static char	get_hex_digit(int d, char c)
{
	char	*base;

	if (c >= 65 && c <= 90)
		base = "0123456789ABCDEF";
	else
		base = "0123456789abcdef";
	return (base[d % 16]);
}
