/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:40:11 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/21 22:46:33 by gcamelo-         ###   ########.fr       */
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

static void	fill_int_string(int n, char *r, int cases)
{
	int				i;
	unsigned int	act_case;

	if (n < 0)
	{
		n = -n;
		*r++ = '-';
	}
	i = 0;
	act_case = 1;
	while (i < cases - 1)
	{
		act_case = act_case * 10;
		i = i + 1;
	}
	while (act_case >= 1)
	{
		*r = n / act_case + '0';
		n = n - act_case * (n / act_case);
		act_case = act_case / 10;
		r = r + 1;
	}
	*r = '\0';
}

char	*ft_itoa(int n)
{
	char	*r;
	int		l;

	if (n == 0)
	{
		r = malloc(2);
		if (!r)
			return (r);
		r[0] = '0';
		r[1] = '\0';
		return (r);
	}
	l = 0;
	if (n < 0)
		l = l + 1;
	l = l + dec_cases(n);
	r = malloc(l + 1);
	if (!r)
		return (r);
	fill_int_string(n, r, dec_cases(n));
	return (r);
}
