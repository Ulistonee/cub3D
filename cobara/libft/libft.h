/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mylib.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cobara <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/28 15:29:42 by cobara            #+#    #+#             */
/*   Updated: 2020/11/28 10:23:47 by cobara           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __LIBFT_H
# define __LIBFT_H

# include <stdlib.h>

typedef struct		s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t				ft_strlen(const char *str);
int					ft_toupper(int ch);
int					ft_tolower(int ch);
int					ft_isascii(int ch);
size_t				ft_strlcpy(char *dst, const char *src, size_t size);
size_t				ft_strlcat(char *dst, const char *src, size_t size);
char				*ft_strchr(const char *str, int ch);
char				*ft_strrchr(const char *str, int ch);
int					ft_isdigit(int ch);
void				ft_bzero(void *s, size_t n);
void				*ft_memset(void *dest, int c, size_t n);
void				*ft_memcpy(void *desination, const void *source, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memmove(void *dest, const void *source, size_t n);
void				*ft_memchr(const void *arr, int c, size_t n);
int					ft_memcmp(const void *arr1, const void *arr2, size_t n);
int					ft_strncmp(const char *str1, const char *str2, size_t n);
char				*ft_strnstr(const char *hay, const char *need, size_t len);
int					ft_isalpha(int ch);
int					ft_isalnum(int ch);
int					ft_atoi(const char *str);
void				*ft_calloc(size_t number, size_t size);
char				*ft_strdup(const char *str);
char				*ft_substr(char const *s, unsigned int start, size_t len);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s1, char const *set);
char				*ft_itoa(int n);
char				**ft_split(char const *s, char c);
void				ft_putendl_fd(char *s, int fd);
void				ft_putnbr_fd(int n, int fd);
t_list				*ft_lstnew(void *content);
int					ft_lstsize(t_list *lst);
void				ft_lstadd_front(t_list **lst, t_list *new);
t_list				*ft_lstlast(t_list *lst);
void				ft_lstdelone(t_list *lst, void (*del)(void *));
void				ft_lstclear(t_list **lst, void (*del)(void *));
void				ft_lstiter(t_list *lst, void (*f)(void *));
int					ft_isprint(int ch);
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void				ft_putchar_fd(char c, int fd);
void				ft_putstr_fd(char *s, int fd);
t_list				*ft_lstmap(t_list *lst, void *(*f)(void *),
		void (*del)(void *));
void				ft_lstadd_back(t_list **lst, t_list *new);

#endif
