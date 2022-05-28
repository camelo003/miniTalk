/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:06:46 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:06:47 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memcpy(void *dest, const void *src, unsigned int n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	if (!dest && !src)
		return ((void *)0);
	while (i < n)
	{
		d = dest + i;
		s = src + i;
		*d = *s;
		i = i + 1;
	}
	return (dest);
}
