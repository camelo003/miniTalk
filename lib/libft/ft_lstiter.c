/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:47:50 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:48:21 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		if (lst->next == (void *)0)
		{
			(*f)(lst->content);
		}
		else
		{
			ft_lstiter(lst->next, f);
			(*f)(lst->content);
		}
	}
}
