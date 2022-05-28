/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:14:45 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/21 22:54:29 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	unsigned int	l;
	char			*r;

	if (!s)
		return ((void *)0);
	i = 0;
	l = ft_strlen(s);
	r = malloc(l + 1);
	if (!r)
		return (r);
	while (i < l)
	{
		r[i] = (*f)(i, s[i]);
		i = i + 1;
	}
	r[i] = '\0';
	return (r);
}
