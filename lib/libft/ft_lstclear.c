/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:45:43 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:46:03 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*t;

	t = *lst;
	if (t->next == (void *)0)
	{
		(*del)(t);
	}
	else
	{
		ft_lstclear(&(t->next), del);
		(*del)(t);
	}
	*lst = (void *)0;
}
