/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.sp>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:50:26 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:50:45 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*act_t;
	void	*act_content;

	if (!lst)
		return ((void *)0);
	act_t = malloc(sizeof(t_list));
	act_content = (*f)(lst->content);
	act_t->content = act_content;
	if (lst->next == (void *)0)
		act_t->next = (void *)0;
	else
		act_t->next = ft_lstmap(lst->next, f, del);
	return (act_t);
}
