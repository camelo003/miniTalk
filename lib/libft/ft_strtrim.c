/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:33:42 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 01:34:21 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	trim_begin(char const *s1, char const *set)
{
	unsigned int	i;

	i = 0;
	while (ft_strchr(set, s1[i]))
		i = i + 1;
	return (i);
}

static unsigned int	trim_end(char const *s1, char const *set)
{
	int	s1_l;
	int	i;

	s1_l = ft_strlen(s1);
	i = 1;
	while (ft_strchr(set, s1[s1_l - i]))
		i = i + 1;
	return (i - 1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int		begin;
	int		end;
	char	*r;
	int		l;

	if (!s1)
		return ((void *)0);
	if (ft_strlen(set) == 0)
		return (ft_strdup(s1));
	begin = trim_begin(s1, set);
	l = ft_strlen(s1);
	if (l <= begin || ft_strlen(s1) == 0)
		return (ft_strdup(""));
	end = trim_end(s1, set);
	r = ft_substr(s1, begin, l - begin - end);
	return (r);
}
