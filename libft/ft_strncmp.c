/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:59:02 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:28:58 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		diff;

	i = 0;
	while (i < n)
	{
		diff = (char) s1[i] - (char) s2[i];
		if (diff != 0 || s1[i] == '\0')
			return (diff);
		i++;
	}
	return (0);
}

// int main () {
// 	char myStr1[] = "ABCDE12999";
// 	char myStr2[] = "ABCDE12";
// 	size_t n = 8;
//     printf("   strncmp() -> %d\n", strncmp(myStr1, myStr2, n));
//     printf("my_strncmp() -> %d\n", ft_strncmp(myStr1, myStr2, n));
// 	return 0;
// }