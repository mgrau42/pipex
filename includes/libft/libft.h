/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mgrau <mgrau@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/07 10:27:07 by mgrau             #+#    #+#             */
/*   Updated: 2022/03/07 13:38:00 by mgrau            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include <unistd.h>
# include "get_next_line.h"

int				ft_revstrncmp(char *s1, char *s2, unsigned int n);
char			*ft_strcpy(char *dest, char *src);
int				ft_toupper(int c);
char			*ft_strrchr(char *str, int c);
char			*ft_strnstr(char *str, char *to_find, unsigned int len);
int				ft_tolower(int c);
int				ft_strncmp(char *s1, char *s2, unsigned int n);
int				ft_strlen(char *str);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
char			*ft_strchr(char *str, int c);
void			*ft_memset(void *str, int c, size_t n);
void			*ft_memmove(void *dest, const void *src, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, unsigned int n);
int				ft_memcmp(const void *s1, const void *s2, unsigned int n);
void			*ft_memchr(const void *src, int c, size_t n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
int				ft_isprint(int c);
int				ft_isascii(int c);
int				ft_isalpha(int c);
int				ft_isalnum(int c);
int				ft_isdigit(int c);
void			*ft_bzero(void *str, size_t n);
int				ft_atoi(char *str);
char			*ft_strdup(const char *str1);
void			*ft_calloc(size_t num, size_t size);
char			*ft_itoa(int n);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			**ft_split(char const *s, char c);
void			ft_putchar_fd(char c, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstadd_front(t_list **alst, t_list *new);
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *t, void *(*f)(void *), void (*d)(void *));
t_list			*ft_lstnew(void *content);
int				ft_lstsize(t_list *lst);
void			ft_int_order(int *order, int *var, int size);
int				*ft_intdup(int *str1, int nsize);
int				ft_charcount(char *str, char c);
unsigned int	ft_strcat(char *dest, char *src);
unsigned int	ft_strcharcpy(char *d, char *src, char u, unsigned int pos);
char			*init_str(int n, unsigned int len);
int				which_num(int n);
char			**init_matrix(char const *s, char c);
char			*init_string(int size);
#endif
