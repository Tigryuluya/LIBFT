/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 12:55:56 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:27:49 by sshadrin         ###   ########.fr       */
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

// 	temp = (char *) dest_str;
// 	while (count--)
// 	{
// 		*temp++ = *(char *) src_str++;
// 	}
// 	return (dest_str);
// }

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	s1_size;
	size_t	s2_size;
	char	*memory;

	s1_size = strlen(s1);
	s2_size = strlen(s2);
	memory = malloc(s1_size + s2_size + 1);
	if (!memory)
		return (NULL);
	memcpy(memory, s1, s1_size);
	memcpy(memory + s1_size, s2, s2_size + 1);
	return (memory);
}

// int main () {
// 	char *string = ft_strjoin("Hallo ", "Whispend!");

// 	printf("%s\n", string);

// 	return 0;
// }