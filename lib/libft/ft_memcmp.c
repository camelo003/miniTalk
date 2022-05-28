/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:06:30 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:06:32 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_memcmp(const void *s1, const void *s2, unsigned int n)
{
	unsigned int	i;
	unsigned char	*c1;
	unsigned char	*c2;

	if (n == 0)
		return (0);
	i = 0;
	while (i < n)
	{
		c1 = (unsigned char *)s1 + i;
		c2 = (unsigned char *)s2 + i;
		if (*c1 != *c2)
			return (*c1 - *c2);
		i = i + 1;
	}
	return (0);
}
