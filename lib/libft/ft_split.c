/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:10:52 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:10:53 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_splits(char const *s, char c)
{
	int	i;
	int	splits;

	i = 0;
	splits = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			splits = splits + 1;
		i = i + 1;
	}
	return (splits);
}

static int	ft_get_first_valid(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c)
			break ;
		i = i + 1;
	}
	return (i);
}

static int	ft_get_last_valid(char *s, char c)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			break ;
		i = i + 1;
	}
	return (i);
}

static char	*ft_get_split(char **s, char c)
{
	int		first_valid;
	int		last_valid;
	char	*r;
	int		i;

	first_valid = ft_get_first_valid(*s, c);
	last_valid = ft_get_last_valid(*s, c) + 1;
	r = ft_calloc((last_valid - first_valid + 1), sizeof(char));
	i = 0;
	while (first_valid + i < last_valid)
	{
		r[i] = *((*s) + i + first_valid);
		i = i + 1;
	}
	*s = *s + last_valid;
	r[i] = '\0';
	return (r);
}

char	**ft_split(char const *s, char c)
{
	int		splits;
	char	**r;
	char	*s_p;
	int		i;

	if (!s)
		return ((void *)0);
	splits = ft_splits(s, c);
	r = ft_calloc((splits + 1), sizeof(char *));
	if (!r)
		return ((void *)0);
	i = 0;
	s_p = (char *)s;
	while (i < splits)
		r[i++] = ft_get_split(&s_p, c);
	r[i] = (void *)0;
	return (r);
}
