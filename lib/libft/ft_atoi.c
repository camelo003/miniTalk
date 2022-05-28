/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:22:15 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 01:22:35 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_variables(int *i, int *r, short int *s, short int *h)
{
	*i = 0;
	*r = 0;
	*s = 1;
	*h = 0;
}

static short int	is_dissmissable(char c)
{
	return (c <= 32 || c == '\e');
}

static void	solve_result(char c, short int *has_digit, int *result)
{
	*has_digit = 1;
	*result = *result * 10 + (c - '0');
}

static int	solve_sign(const char *s, int i, short int	*hd, short int *sign)
{
	if (s[i] == '-' || s[i] == '+')
	{
		if (*hd)
			return (1);
		if (!ft_isdigit(s[i + 1]))
		{
			*hd = 1;
			return (1);
		}
		if (s[i] == '-')
			*sign = -1;
	}
	return (0);
}

int	ft_atoi(const char *s)
{
	int			i;
	int			result;
	short int	sign;
	short int	has_digit;

	init_variables(&i, &result, &sign, &has_digit);
	while (s[i] != '\0')
	{
		if (is_dissmissable(s[i]) || solve_sign(s, i, &has_digit, &sign))
		{
			if (has_digit || s[i] == '\e')
				break ;
		}
		else if (ft_isdigit(s[i]))
			solve_result(s[i], &has_digit, &result);
		else if (s[i] == '-' || s[i] == '+')
			;
		else if (has_digit)
			break ;
		else
			return (0);
		i = i + 1;
	}
	return (result * sign);
}
