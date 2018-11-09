/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erli <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 16:40:19 by erli              #+#    #+#             */
/*   Updated: 2018/11/09 16:27:07 by erli             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>

typedef	struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

size_t			ft_strlen(const char *str);
char			*ft_strdup(const char *src);
void			*ft_memset(void *b, int c, size_t len);
void			ft_bzero(void *s, size_t len);
void			*ft_memcpy(void *restrict dsl, const void *restrict src,
					size_t n);
void			*ft_memccpy(void *restrict dst, const void *restrict src, int c,
					size_t n);
void			*ft_memmove(void *dsl, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t n);
char			*ft_strcat(char *restrict s1, const char *restrict s2);
char			*ft_strncat(char *restrict s1, const char *restrict s2,
					size_t n);
size_t			ft_strlcat(char *restrict s1, const char *restrict s2,
					size_t n);
char			*ft_strchr(const char *str, int c);
char			*ft_strrchr(const char *str, int c);
char			*ft_strstr(const char *haysack, const char *needle);
char			*ft_strnstr(const char *haysack, const char *needle, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t n);
void			ft_memdel(void **ptr);
char			*ft_strnew(size_t n);
void			ft_strdel(char **ptr);
void			ft_strclr(char *str);
void			ft_striter(char *str, void (*f)(char *));
void			ft_striteri(char *str, void (*f)(unsigned int, char*));
char			*ft_strmap(const char *src, char (*f)(char));
char			*ft_strmapi(const char *src, char (*f)(unsigned int, char));
int				ft_strequ(const char *s1, const char *s2);
int				ft_strnequ(const char *s1, const char *s2, size_t n);
char			*ft_strsub(const char *src, unsigned int start, size_t len);
char			*ft_strjoin(const char *s1, const char *s2);
char			*ft_strtrim(const char *src);
char			**ft_strsplit(const char *src, char c);
char			*ft_itoa(int nb);
void			ft_putchar(char c);
void			ft_putstr(const char *str);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *str, int fd);
void			ft_putendl(char *str);
void			ft_putendl_fd(char *str, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(const void *content, size_t content_size);
void			ft_lstdelone(t_list **alist, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alist, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alist, t_list *new);
void			ft_lstiter(t_list *list, void (*f)(t_list *));
t_list			*ft_lstmap(t_list *list, t_list *(*f)(t_list *));

void			ft_strtoupper(char *str);
void			ft_strtolower(char *str);
void			ft_charatpos(unsigned int i, char *str);
char			ft_charrevcap(char c);
char			ft_charcapifeven(unsigned int i, char c);
void			ft_printstrsplit(char **split);
void			ft_putmem(void *ptr, size_t n);
void			ft_putlst(t_list *list);
void			ft_lstreverse(t_list *list);
void			ft_lstaddlast(t_list **alist, t_list *new);
void			ft_memdellst(void *ptr, size_t n);
void			ft_printlstone(t_list *elem);
t_list			*ft_lsttoupper(t_list *elem);

#endif
