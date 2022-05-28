/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 02:16:00 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/21 22:43:28 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(unsigned int nmemb, unsigned int size)
{
	void	*r;

	r = malloc(nmemb * size);
	if (r)
		ft_memset(r, 0, nmemb * size);
	return (r);
}
