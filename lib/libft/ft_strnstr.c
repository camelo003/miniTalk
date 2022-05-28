/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:36:11 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 01:36:29 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	init_variables(unsigned int *h, unsigned int *n, short int *match)
{
	*h = 0;
	*n = 0;
	*match = 0;
}

char	*ft_strnstr(const char *haystack, const char *needle, unsigned int s)
{
	unsigned int	h;
	unsigned int	n;
	short int		match;

	init_variables(&h, &n, &match);
	if (ft_strncmp(needle, "", 1) == 0)
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < s)
	{
		if (haystack[h] == needle[n])
		{
			match = 1;
			while (needle[n] != '\0')
			{
				if (haystack[h + n] != needle[n] || h + n > s)
					match = 0;
				n = n + 1;
			}
			if (match)
				return ((char *)(haystack + h));
			n = 0;
		}
		h = h + 1;
	}
	return ((char *)0);
}
