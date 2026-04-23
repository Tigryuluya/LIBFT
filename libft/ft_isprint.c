/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 10:43:52 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:14:15 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int ft_isprint (int c)
{
	if (c >= 0 && c <= 31)
		return (0);
	return (1);
}

// int main () {
// 	int  i     = 0;
// 	char str[] = "first line \n second line \n";
// 	while (isprint(str[i])) {
// 		putchar (str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	printf("\n");
// 	{
// 		int  i     = 0;
// 		char str[] = "first line \n second line \n";
// 		while (ft_isprint(str[i])) {
// 			putchar (str[i]);
// 			i++;
// 		}
// 	}
// 	printf("\n");
// 	printf("\n");
// 	return 0;
// }