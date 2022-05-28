/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gcamelo- <gcamelo-@student.42sp.o...>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/18 01:21:03 by gcamelo-          #+#    #+#             */
/*   Updated: 2022/02/24 03:48:27 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

short int		ft_isalpha(unsigned int i);

short int		ft_isdigit(unsigned int i);

short int		ft_isalnum(unsigned int i);

short int		ft_isascii(unsigned int i);

short int		ft_isprint(unsigned int i);

int				ft_toupper(int c);

int				ft_tolower(int c);

int				ft_atoi(const char *s);

void			*ft_memset(void *s, int c, unsigned int n);

void			*ft_memcpy(void *dest, const void *src, unsigned int n);

void			*ft_memmove(void *dest, const void *src, unsigned int n);

void			*ft_memchr(const void *s, int c, unsigned int n);

int				ft_memcmp(const void *s1, const void *s2, unsigned int n);

void			ft_bzero(void *s, unsigned int n);

unsigned int	ft_strlen(const char *s);

unsigned int	ft_strlcpy(char *dst, const char *src, unsigned int size);

unsigned int	ft_strlcat(char *dst, const char *src, unsigned int size);

char			*ft_strchr(const char *s, int c);

char			*ft_strrchr(const char *s, int c);

int				ft_strncmp(const char *s1, const char *s2, unsigned int n);

char			*ft_strnstr(const char *haystack,
					const char *needle,
					unsigned int s);

void			*ft_calloc(unsigned int nmemb, unsigned int size);

char			*ft_strdup(const char *s);

char			*ft_substr(char const *s, unsigned int start, unsigned int len);

char			*ft_strjoin(char const *s1, char const *s2);

char			*ft_strtrim(char const *s1, char const *set);

char			**ft_split(char const *s, char c);

char			*ft_itoa(int n);

char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));

void			ft_striteri(char *s, void (*f)(unsigned int, char*));

void			ft_putchar_fd(char c, int fd);

void			ft_putstr_fd(char *s, int fd);

void			ft_putendl_fd(char *s, int fd);

void			ft_putnbr_fd(int n, int fd);

typedef struct s_list
{
	char			*content;
	struct s_list	*next;
}	t_list;

t_list			*ft_lstnew(void *content);

void			ft_lstadd_front(t_list **lst, t_list *new);

int				ft_lstsize(t_list *lst);

t_list			*ft_lstlast(t_list *lst);

void			ft_lstadd_back(t_list **lst, t_list *new);

void			ft_lstdelone(t_list *lst, void (*del)(void*));

void			ft_lstclear(t_list **lst, void (*del)(void*));

void			ft_lstiter(t_list *lst, void (*f)(void *));

t_list			*ft_lstmap(t_list *lst,
					void *(*f)(void *),
					void (*del)(void *));

int				eol_in_it(const char *s);

unsigned int	gnl_strlen(const char *s);

void			gnl_memcpy(void *dest,
					const void *src,
					unsigned int src_offset,
					unsigned int n);

void			*gnl_memset(void *s, int c,
					unsigned int n);

char			*get_next_line(int fd);

typedef struct s_fmt
{
	char	type;
	int		pad;
}	t_fmt;

int				ft_solve_char(char c);

int				ft_solve_str(char *s);

int				ft_solve_ptr(long unsigned p, t_fmt fmt);

int				ft_solve_int(long i);

int				ft_solve_unsig(unsigned long i);

int				ft_solve_hex(unsigned int i, t_fmt fmt);

int				ft_printf(const char *s, ...);

#endif
