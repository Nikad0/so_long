/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: erbuffet <erbuffet@student.42lyon.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/22 09:21:27 by erbuffet          #+#    #+#             */
/*   Updated: 2025/03/07 17:09:15 by erbuffet         ###   ########lyon.fr   */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef FD_SIZE
#  define FD_SIZE 1024
# endif
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_substr(char const *s, size_t start, size_t len);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char *s1, const char *s2);
char	*ft_strstr(char *str, char *to_find);
char	**ft_split(char const *s, char c);
char	*ft_strrchr(const char *s, int c);
int		ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s);
char	*ft_itoa(int n);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
int		ft_tolower(int c);
int		ft_toupper(int c);
int		ft_isascii(int c);
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isprint(int c);
void	*ft_memmove(void *destination, const void *source, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char *));
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
size_t	ft_strlcat(char *dest, const char *src, size_t size);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
size_t	ft_strlen(const char *str);
int		print_ptr(unsigned long nbr, char *base, int mod);
int		print_hex(unsigned int nbr, char *base);
int		print_unsigned_nbr(unsigned int arg);
int		ft_printf(const char *format, ...) __attribute__((format(printf, 1,
					2)));
int		print_str(char *arg);
int		print_nbr(int arg);
int		print_char(int c);
char	*get_next_line(int fd);
char	*ft_strcpy(char *dst, const char *src);
char	ft_next_line(char line, int new_line);
char	*ft_stradd(char *str, char buff);
int		gnl(int fd, char **str);
#endif