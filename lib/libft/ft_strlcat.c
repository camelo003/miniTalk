/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:13:07 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:13:08 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size)
{
	unsigned int	d_len;
	unsigned int	i;

	d_len = 0;
	if (size > 0)
	{
		while (dst[d_len] != '\0' && d_len < size)
			d_len = d_len + 1;
		i = 0;
		if (d_len < size)
		{
			while (d_len + i < size - 1 && src[i] != '\0')
			{
				dst[d_len + i] = src[i];
				i = i + 1;
			}
			dst[d_len + i] = '\0';
		}
	}
	return (d_len + ft_strlen(src));
}
