/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:08:49 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:27:00 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int ch)
{
	int	i;

	i = -1;
	while (str[++i] != '\0')
		if (str[i] == ch)
			return ((char *) str + i);
	return (NULL);
}

// int main () {
//     const char* str = "GeeksforGeeks";
//     char        ch  = 'o';

// 	const char* result = ft_strchr(str, ch);

//     printf("Character: %s\n",  result);

// 	return 0;
// }