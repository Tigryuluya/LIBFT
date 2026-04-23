/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 16:44:15 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:27:31 by sshadrin         ###   ########.fr       */
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

// void	*ft_memcpy(void *dest_str, const void *src_str, int count)
// {
// 	char	*temp;

// 	temp = (char *) dest_str;
// 	while (count--)
// 	{
// 		*temp++ = *(char *) src_str++;
// 	}
// 	return (dest_str);
// }

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*memory;

	if (NULL == src)
		return (NULL);
	len = ft_strlen(src) + 1;
	memory = malloc(len);
	if (memory)
		return (NULL);
	return ((char *) ft_memcpy(memory, src, len));
}

// int main () {
// 	char source[] = "GeeksForGeeks";

//     printf("%s", ft_strdup(source));

// 	return 0;
// }