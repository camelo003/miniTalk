/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:07:11 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:07:12 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	is_backward(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		if (src + i == dest)
			return (1);
		i = i + 1;
	}
	return (0);
}

void	*ft_memmove(void *dest, const void *src, unsigned int n)
{
	int			i;
	char		*d;
	const char	*s;

	if (!dest && !src)
		return ((void *)0);
	if (is_backward(dest, src, n))
	{
		i = (int)n - 1;
		while (i >= 0)
		{
			d = dest + i;
			s = src + i;
			*d = *s;
			i = i - 1;
		}
	}
	else
	{
		ft_memcpy(dest, src, n);
	}
	return (dest);
}
