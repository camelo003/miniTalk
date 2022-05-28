/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/23 04:52:32 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/05/23 04:52:52 by gcamelo-         ###   ########.sp       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	if (!lst)
		return (0);
	if (lst->next == (void *)0)
		return (1);
	else
		return (ft_lstsize(lst->next) + 1);
}
