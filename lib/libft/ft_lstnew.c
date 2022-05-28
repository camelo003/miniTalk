/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:52:01 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:52:15 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*t;

	t = malloc(sizeof(t_list));
	if (t == (void *)0)
		return (t);
	t->content = content;
	t->next = (void *)0;
	return (t);
}
