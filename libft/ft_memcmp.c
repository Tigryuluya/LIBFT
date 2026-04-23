/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 15:32:55 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:41:10 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t len)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	str1 = (unsigned char *) s1;
	str2 = (unsigned char *) s2;
	i = 0;
	while (i <= len)
		if (str1[i] != str2[i])
			return (str1[i] - str2[i]);
	return (0);
}

// int main () {
// 	char str1[] = "abcdef";
// 	char str2[] = "ABCDEF";

// 	printf("ft_memcmp: %d\n", ft_memcmp(str1, str2, 5));
// 	printf("   memcmp: %d\n", memcmp(str1, str2, 5));

// 	return 0;
// }