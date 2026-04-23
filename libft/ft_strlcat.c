/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/16 12:09:03 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:28:10 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// size_t	ft_strlen(const char *str)
// {
// 	size_t	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

// void	*ft_memcpy(void *dest_str, const void *src_str, size_t count)
// {
// 	char	*temp;

// 	*temp = (char *) dest_str;
// 	while (count--)
// 	{
// 		*temp++ = *(char *) src_str++;
// 	}
// 	return (dest_str);
// }

size_t	ft_strlcat(char *dest, const char *src, size_t d_size)
{
	size_t	s_len;
	size_t	d_len;

	s_len = ft_strlen(src);
	d_len = ft_strlen(dest);
	if (d_len >= d_size)
		d_len = d_size;
	if (d_len == d_size)
		return (d_size + s_len);
	if (s_len < (d_size - s_len))
	{
		ft_memcpy(dest + d_len, src, s_len);
		dest[d_len + s_len] = '\0';
	}
	else
	{
		ft_memcpy(dest + d_len, src, d_size - d_len - 1);
		dest[d_size - 1] = '\0';
	}
	return (d_len + s_len);
}

// int main () {
// 	char dest[50] = "Hello, ";
// 	const char src[] = "World!";
// 	size_t d_size = 10; // * 50 lenght
// 	const size_t count_of_string = ft_strlcat(dest, src, d_size);
// 	printf("lenght: %zu, string: '%s'\n", count_of_string, dest);
// 	return 0;
// }