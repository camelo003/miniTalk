/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/21 03:40:40 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 01:48:53 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char		*ft_solve_formater(char *ptr, unsigned int *cnt, va_list *ap);

static t_fmt	ft_get_format(char *s);

int	ft_printf(const char *s, ...)
{
	char			*ptr;
	unsigned int	count;
	va_list			ap;

	va_start(ap, s);
	ptr = (char *)s;
	count = 0;
	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr = ft_solve_formater(ptr, &count, &ap);
			continue ;
		}
		write(1, ptr, 1);
		ptr = ptr + 1;
		count = count + 1;
	}
	va_end(ap);
	return (count);
}

static char	*ft_solve_formater(char *ptr, unsigned int *cnt, va_list *ap)
{
	t_fmt	fmt;

	fmt = ft_get_format(ptr);
	if (fmt.type == '\0')
		return (ptr + fmt.pad);
	else if (fmt.type == 'c')
		*cnt = *cnt + ft_solve_char((char)va_arg(*ap, int));
	else if (fmt.type == 's')
		*cnt = *cnt + ft_solve_str(va_arg(*ap, char *));
	else if (fmt.type == 'p')
		*cnt = *cnt + ft_solve_ptr(va_arg(*ap, long), fmt);
	else if (fmt.type == 'd' || fmt.type == 'i')
		*cnt = *cnt + ft_solve_int(va_arg(*ap, int));
	else if (fmt.type == 'u')
		*cnt = *cnt + ft_solve_unsig(va_arg(*ap, unsigned int));
	else if (fmt.type == 'x' || fmt.type == 'X')
		*cnt = *cnt + ft_solve_hex(va_arg(*ap, int), fmt);
	else if (fmt.type == '%')
	{
		*cnt = *cnt + 1;
		write(1, "%", 1);
	}
	return (ptr + fmt.pad);
}

static t_fmt	ft_get_format(char *s)
{
	t_fmt	fmt;
	int		i;

	i = 1;
	while (ft_strchr("0123456789-# +.cspdiuxX%", s[i]))
	{
		if (ft_strchr("cspdiuxX%", s[i]))
		{
			fmt.type = s[i];
			fmt.pad = i + 1;
			return (fmt);
		}
		i = i + 1;
	}
	fmt.type = '\0';
	fmt.pad = i;
	return (fmt);
}
