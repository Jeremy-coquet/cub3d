/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gudoyle <gudoyle@student.42quebec.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/12 12:44:21 by gudoyle           #+#    #+#             */
/*   Updated: 2024/11/27 08:27:54 by gudoyle          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <stdio.h>

long		ft_atoi(const char *str);
size_t		ft_strlen(const char *str);
void		ft_bzero(void *s, size_t n);
int			ft_isalpha(int c);
int			ft_isalnum(int c);
int			ft_isascii(int c);
int			ft_isdigit(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);
char		*ft_strnstr(const char *haystack, const char *needle, size_t len);
char		*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char		*ft_strdup(const char *s1);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int n, int fd);
void		ft_putendl_fd(char *s, int fd);
void		ft_putstr_fd(char *s, int fd);
char		*ft_strchr(const char *s, int c);
char		*ft_strrchr(const char *s, int c);
void		ft_striteri(char *s, void (*f)(unsigned int, char*));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_itoa(int n);
size_t		ft_strlcpy(char *dst, const char *src,
				size_t dstsize);
int			ft_strncmp(const char *s1, const char *s2, size_t n);
char		*ft_strtrim(char const *s1, char const *set);
void		*ft_memset(void *b, int c, size_t len);
void		*ft_memcpy(void *dst, const void *src, size_t n);
void		*ft_memmove(void *dst, const void *src, size_t len);
void		*ft_memchr(const void *s, int c, size_t n);
int			ft_memcmp(const void *s1, const void *s2, size_t n);
void		*ft_calloc(size_t count, size_t size);
size_t		ft_strlcat(char *dst, const char *src, size_t dstsize);
char		*ft_strjoin(char const *s1, char const *s2);
char		**ft_split(char const *s, char c);
int			ft_printf(const char *input, ...);
void		ft_putchar_pf(char c, size_t *count);
void		ft_putstr_pf(char *str, size_t *count);
void		ft_putnbr_pf(int n, size_t *count);
void		ft_putnbr_u_pf(unsigned int n, size_t *count);
void		ft_puthex_pf(const char *type, unsigned long long n, size_t *count);
void		ft_putnbr_base_pf(char *base, unsigned long long n, size_t *count);
void		ft_putptr_pf(void *ptr, size_t *count);
char		*get_next_line(int fd);

#endif