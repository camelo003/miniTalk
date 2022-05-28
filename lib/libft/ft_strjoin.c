/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:12:49 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/21 22:52:54 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*r;
	unsigned int	len_1;
	unsigned int	len_2;

	if (!s1 || !s2)
		return ((void *)0);
	len_1 = ft_strlen(s1);
	len_2 = ft_strlen(s2);
	r = malloc(len_1 + len_2 + 1);
	if (!r)
		return ((void *)0);
	ft_strlcpy(r, s1, len_1 + 1);
	ft_strlcpy(r + len_1, s2, len_2 + 1);
	return (r);
}
