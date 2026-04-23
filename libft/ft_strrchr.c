/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/19 13:15:37 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:32:34 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// int	ft_strlen(const char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i])
// 	{
// 		i++;
// 	}
// 	return (i);
// }

char	*ft_strrchr(const char *str, int c)
{
	size_t	i;
	size_t	str_len;

	i = -1;
	str_len = ft_strlen(str);
	while (++i <= str_len)
		if (str[str_len - i] == (char) c)
			return ((char *) &str[str_len - i]);
	return (NULL);
}

// int main () {
// 	const char str[] = "https://www.tutorialspoint.com";
// 	const char ch    = '.';

// 	char *result = strrchr(str, ch);

// 	printf("%c   -   %s\n", ch, result);

// 	return 0;
// }