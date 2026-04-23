/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/15 13:08:16 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:37:03 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	size_t		i;

	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
		return (NULL);
	while (i <= count)
		tmp[i++] = 0;
	return (tmp);
}

// int main () {
//     int *arr_v2 = ft_calloc(15, sizeof(char));
//     printf("%p ->  ", arr_v2);
//     for (int i = 0; i < 15; i++) {
//         printf("%d ", arr_v2[i]);
//     }
// 	printf("\n\n");
//     int *arr = calloc(15, sizeof(char));
// 	printf("%p ->  ", arr);
//     for (int i = 0; i < 15; i++) {
//         printf("%d ", arr[i]);
//     }
// 	return 0;
// }