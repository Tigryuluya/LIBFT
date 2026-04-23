/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:13:25 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:58:46 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "termios.h"
#include <fcntl.h>

/* --------------- CHARS --------------- */
int	ft_isalpha(int c);
int	ft_isdigit(int c);
int	ft_isalnum(int c);
int	ft_isascii(int c);
int	ft_isprint(int c);
int	ft_toupper(int c);
int	ft_tolower(int c);

/* --------------- STRINGS --------------- */
size_t	ft_strlen(const char *str);
size_t	ft_strlcat(char *dest, const char *src, size_t d_size);
char	*ft_strrchr(const char *str, int c);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strchr(const char *str, int ch);
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
char	*ft_strdup(const char *src);
/* --------------- PART 2 --------------- */
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	**ft_split(char const *s, char c);

/* --------------- MEMORY --------------- */
void	*ft_memset(void *str, int c, size_t len);
void	ft_bzero(void *str, size_t len);
void	*ft_memcpy(void *dest_str, const void *src_str, size_t len);
void	*ft_memmove(void *dest_str, const void *src, size_t len);
void	*ft_memchr(const void *str, int c, size_t len);
int	    ft_memcmp(const void *s1, const void *s2, size_t len);
void	*ft_calloc(size_t count, size_t size);

/* --------------- NUMBERS --------------- */
int	ft_atoi(const char *str);

#endif