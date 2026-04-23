/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:03:03 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:30:15 by sshadrin         ###   ########.fr       */
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

// size_t	ft_strlcpy(char *dest, const char *src, size_t size)
// {
// 	size_t	i;

// 	i = 0;
// 	if (size > 0)
// 	{
// 		while (src[i] && i < (size - 1))
// 		{
// 			dest[i] = src[i];
// 			i++;
// 		}
// 		dest[i] = '\0';
// 	}
// 	return (ft_strlen(src));
// }

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*cursor_s;
	char	*memory;
	size_t	size;

	if (!s)
		return (NULL);
	else if (ft_strlen(s) < (size_t) start)
		return ("");
	cursor_s = (char *) s + start;
	if (ft_strlen(cursor_s) < len)
		size = ft_strlen(cursor_s) + 1;
	else
		size = len + 1;
	memory = malloc(size * 1);
	if (!memory)
		return (NULL);
	ft_strlcpy(memory, cursor_s, size);
	return (memory);
}

// int main () {
// 	char str[]    = "This is original string!";
// 	char *new_str = ft_substr(str, 5, 19);

// 	printf("%s\n", new_str);

// 	return 0;
// }