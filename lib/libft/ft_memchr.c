/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:05:44 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/18 02:05:45 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	*ft_memchr(const void *s, int c, unsigned int n)
{
	const char		*i_char;
	unsigned int	i;
	void			*r;

	i = 0;
	r = 0;
	while (i < n)
	{
		i_char = s + i;
		if (*i_char == c)
		{
			r = (void *)i_char;
			break ;
		}
		i = i + 1;
	}
	return (r);
}
