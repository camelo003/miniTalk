/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:49:20 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:49:45 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (!lst)
		return ((void *)0);
	if (lst->next == (void *)0)
		return (lst);
	else
		return (ft_lstlast(lst->next));
}
