/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:11:36 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:11:39 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i = i + 1;
	}
	if (c == '\0')
		return ((char *)(s + i));
	if (ft_strncmp(s, "", 1) == 0 && ft_strncmp(s, "\0", 1))
		return ((char *)s);
	return ((char *)0);
}
