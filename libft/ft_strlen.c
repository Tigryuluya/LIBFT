/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 10:56:57 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 16:48:55 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i++])
		;
	return (i);
}

// #include <stdio.h>
// #include <string.h>
// int main () {
// 	char str[]        = "my string is very gross..."; // 26 counts

// 	int lenght        = strlen(str);
// 	int lenght_custom = ft_strlen(str);

// 	printf("Lenght original string is: %d", lenght);

// 	printf("\n");

// 	printf("Lenght custom string is: %d", lenght_custom);

// 	return 0;
// }