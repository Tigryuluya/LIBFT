/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:19:35 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:41:24 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t len)
{
	size_t	i;
	char	*temp;

	i = -1;
	temp = (char *) str;
	while (++i <= len)
		if ((char) temp[i] == (char) c)
			return ((char *) &temp[i]);
	return (NULL);
}

// int main () {
//    const char str[] = "Welcome to India";
//    const char ch = 't';

//    char *result = ft_memchr(str, ch, strlen(str));

//    if (result != NULL) {
//        printf("'%c' found at position %ld\n", ch, result - str);
//    } else {
//        printf("'%c' not found in the string\n", ch);
//    }

// 	return 0;
// }