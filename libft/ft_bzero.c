/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 11:42:55 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:39:26 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *str, size_t len)
{
	size_t	i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (i < len)
		tmp[i++] = 0;
}

// int main () {
// 	char str[] = "This is original...";

// 	ft_bzero(str, 4);

// 	printf("%s", str);

// 	return 0;
// }