/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vpirotti <vpirotti@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:41:52 by vpirotti          #+#    #+#             */
/*   Updated: 2024/11/06 11:41:52 by vpirotti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

int		ft_isprint(int c);
long	ft_isdigit(long c);
int		ft_isascii(int c);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_atoi(const char *str);
int		ft_putnbr_fd(long long int n, int fd);
int		ft_putnbr_base(unsigned long long int nbr, char *base);
char	*ft_itoa(int n);
t_list	*ft_lstnew(void *content);
char	*ft_strchr(const char *s, int c);
int		ft_lstsize(t_list *lst);
char	*ft_strrchr(const char *s, int c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memset(void *mem, int c, size_t size);
void	ft_bzero(void *mem, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	**ft_split(char const *s, char c);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_putstr_fd(char *s, int fd);
void	ft_lstadd_front(t_list **lst, t_list *new);
void	ft_putendl_fd(char *s, int fd);
char	*ft_strnstr(const char *src, const char *tofind, size_t size);
int		ft_putchar_fd(char c, int fd);
void	*ft_calloc(size_t len, size_t size);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void	*ft_memchr(const void *mem, int c, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strdup(const char *src);
int		ft_memcmp(const void *mem1, const void *mem2, size_t size);
char	*ft_substr(char const *s, unsigned int start, size_t len);
t_list	*ft_lstlast(t_list *lst);
size_t	ft_strlen(const char *str);
void	ft_lstadd_back(t_list **lst, t_list *new);
void	*ft_memcpy(void *dest, const void *src, size_t size);
void	*ft_memmove(void *dest, const void *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
void	ft_lstiter(t_list *lst, void (*f)(void *));
int		ft_printf(const char *s, ...);
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstclear(t_list **lst, void (*del)(void*));
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif
