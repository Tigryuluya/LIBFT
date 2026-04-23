/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 15:45:43 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:41:55 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest_str, const void *src, size_t len)
{
	char	*d;
	char	*s;
	size_t	i;

	d = (char *) dest_str;
	s = (char *) src;
	i = -1;
	if (d > s)
		while (len > 0)
		{
			len--;
			d[len] = s[len];
		}
	else
		while (++i < len)
			d[i] = s[i];
	return (dest_str);
}

// int main () {
//           char dest_str[] = "oldstringi";
//     const char src_str[]  = "newstring";

//     printf("Before memmove dest = %s, src = %s\n", dest_str, src_str);

//     ft_memmove(dest_str, src_str, 9);

//     printf("After  memmove dest = %s, src = %s\n", dest_str, src_str);
// }