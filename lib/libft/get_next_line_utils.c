/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/29 00:55:07 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 00:22:42 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

unsigned int	gnl_strlen(const char *s)
{
	unsigned int	i;

	i = 0;
	while (s && *(s + i) != '\0')
		i = i + 1;
	if (i > BUFFER_SIZE)
		i = BUFFER_SIZE;
	return (i);
}

int	eol_in_it(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == '\n')
			return (i);
		i = i + 1;
	}
	return (-1);
}

void	gnl_memcpy(void *dest,
				const void *src,
				unsigned int src_offset,
				unsigned int n)
{
	unsigned int	i;
	char			*d;
	const char		*s;

	i = 0;
	while (i < n)
	{
		d = dest + i;
		s = src + src_offset + i;
		if (i + src_offset < BUFFER_SIZE)
			*d = *s;
		else
			*d = '\0';
		i = i + 1;
	}
}

void	*gnl_memset(void *s, int c, unsigned int n)
{
	unsigned int	i;

	i = 0;
	while (i < n)
	{
		((char *)s)[i] = c;
		i = i + 1;
	}
	return (s);
}
