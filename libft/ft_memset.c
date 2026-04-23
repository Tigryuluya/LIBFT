/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:13:54 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:55:33 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (i < len)
		tmp[i++] = c;
	return (str);
}

// int main () {
// 	char str[] = "This is original...";
// 	ft_memset(str, '#', 4);
// 	printf("%s", str);
// 	return 0;
// }