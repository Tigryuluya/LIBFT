/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 12:01:46 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:43:10 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest_str, const void *src_str, size_t len)
{
	char	*tmp;

	tmp = (char *) dest_str;
	while (len--)
		*tmp++ = *(char *) src_str++;
	return (dest_str);
}

// int main () {
// 	char src[50] = "Tutorialspoint";
// 	char       dest[50];
// 	strcpy(dest, "Heloooo!!");
// 	printf("Before fn, dest = %s\n", dest);
// 	ft_memcpy(dest, src, 5);
// 	printf("After fn, dest = %s\n", dest);
// 	return 0;
// }