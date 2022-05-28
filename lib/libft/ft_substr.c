/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:33:13 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 01:33:14 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, unsigned int len)
{
	unsigned int	l;
	char			*r;
	unsigned int	i;

	if (!s)
		return ((void *)0);
	l = ft_strlen(s);
	if (ft_strlen(s + start) < len)
		r = ft_calloc(ft_strlen(s + start) + 1, sizeof(char));
	else
		r = ft_calloc(len + 1, sizeof(char));
	if (r == (void *)0)
		return (r);
	i = 0;
	while (len > 0 && i < len && (start + i) < l && s[start + i] != '\0')
	{
		r[i] = s[start + i];
		i = i + 1;
	}
	if (l != 0)
		r[i] = '\0';
	return (r);
}
