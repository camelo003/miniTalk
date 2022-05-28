/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:34:45 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 01:34:47 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	unsigned int	i;
	char			*r;

	i = 0;
	r = (char *)0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			r = (char *)(s + i);
		i = i + 1;
	}
	if (c == '\0')
		return ((char *)(s + i));
	return (r);
}
