/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/09 03:22:42 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/22 00:23:25 by gcamelo-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void			init_list_item(t_list **item_p);

static unsigned int	fill_list(t_list **item_p, int fd);

static char			*fill_r(t_list **item_p, unsigned int r_size);

static void			clear_list(t_list **first_item_p,
						t_list **act_item_p, int soft);

char	*get_next_line(int fd)
{
	static t_list	*list = NULL;
	int				chars_read;
	unsigned int	r_size;
	char			*r;

	if (BUFFER_SIZE <= 0)
		return (NULL);
	if (!list)
		init_list_item(&list);
	if (ft_strlen(list->content) == 0)
	{
		chars_read = read(fd, list->content, BUFFER_SIZE);
		if (chars_read <= 0)
		{
			clear_list(&list, &list, 0);
			return (NULL);
		}
	}
	r_size = fill_list(&list, fd);
	r = fill_r(&list, r_size);
	clear_list(&list, &list, 0);
	return (r);
}

static void	init_list_item(t_list **item_p)
{
	t_list	*item;

	if (!*item_p)
		item = ft_calloc(1, sizeof(t_list));
	else
		item = *item_p;
	item->content = ft_calloc(1, BUFFER_SIZE + 1);
	item->next = NULL;
	*item_p = item;
}

static unsigned int	fill_list(t_list **item_p, int fd)
{
	t_list			*act_item;
	unsigned int	len;
	unsigned int	r;

	act_item = *item_p;
	len = gnl_strlen(act_item->content);
	r = 0;
	while ((len == BUFFER_SIZE || act_item->next == NULL)
		&& eol_in_it(act_item->content) == -1)
	{
		init_list_item(&act_item->next);
		if (read(fd, act_item->next->content, BUFFER_SIZE) <= 0)
		{
			clear_list(&act_item->next, &act_item->next, 1);
			len = gnl_strlen(act_item->content);
			break ;
		}
		r = r + len;
		act_item = act_item->next;
		len = gnl_strlen(act_item->content);
	}
	if (eol_in_it(act_item->content) != -1
		&& eol_in_it(act_item->content) <= (int)len)
		len = eol_in_it(act_item->content) + 1;
	return (r + len + 1 + 9);
}

static char	*fill_r(t_list **item_p, unsigned int r_size)
{
	char			*r;
	unsigned int	r_idx;
	t_list			*act;
	int				i;
	int				last_len;

	r = ft_calloc(1, r_size);
	r_idx = 0;
	act = *item_p;
	while (act->next)
	{
		i = 0;
		while (i < BUFFER_SIZE && ((char *)(act->content))[i] != '\0')
			r[r_idx++] = ((char *)(act->content))[i++];
		act = act->next;
	}
	i = 0;
	last_len = gnl_strlen(act->content);
	if (eol_in_it(act->content) != -1 && eol_in_it(act->content) < last_len)
		last_len = eol_in_it(act->content) + 1;
	while (i < last_len)
		r[r_idx++] = ((char *)(act->content))[i++];
	gnl_memcpy(act->content, act->content, last_len, BUFFER_SIZE + 1);
	return (r);
}

static void	clear_list(t_list **first, t_list **act, int soft)
{
	if ((*act)->next)
		clear_list(first, &(*act)->next, soft);
	else
	{
		if (!soft)
			gnl_memcpy((*first)->content, (*act)->content, 0, BUFFER_SIZE + 1);
	}
	if (*first != *act)
	{
		gnl_memset((*act)->content, '\0', BUFFER_SIZE + 1);
		free((*act)->content);
		free((*act)->next);
		(*act)->next = NULL;
		free(*act);
		*act = NULL;
	}
	else
	{
		if (gnl_strlen((*first)->content) == 0)
		{
			free((*first)->content);
			free(*first);
			*first = NULL;
		}
	}
}
