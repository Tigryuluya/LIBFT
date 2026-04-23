/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/23 13:59:01 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 18:13:11 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	to_trim(const char *set, char c)
{
	int	i;

	i = -1;
	while (set[++i] != '\0')
		if (set[i] == c)
			return (1);
	return (0);
}

char	*new_string(const char *str, size_t start, size_t len)
{
	char	*memory;
	size_t	i;

	i = -1;
	if (len <= 0 || start >= ft_strlen(str))
		return (ft_strdup(""));
	memory = malloc(len + 1);
	if (!memory)
		return (NULL);
	while (++i < len)
		memory[i] = str[start + i];
	return (memory);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = -1;
	j = ft_strlen(s1) - 1;
	while (to_trim(set, s1[++i]))
		;
	while (to_trim(set, s1[j]))
	{
		j--;
	}
	return (new_string(s1, i, j - (i - 1)));
}

// int main () {
// 	char *string = ft_strtrim("    New new     news   ", " ");

// 	printf("'%s'\n", string);

// 	return 0;
// }