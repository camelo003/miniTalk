/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:11:56 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:12:02 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char			*r;
	unsigned int	len;

	len = ft_strlen(s);
	r = ft_calloc(len + 1, sizeof(char));
	if (!r || len == 0)
		return (r);
	ft_strlcpy(r, s, len + 1);
	return (r);
}
