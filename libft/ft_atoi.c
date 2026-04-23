/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sshadrin <sshadrin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/14 17:25:51 by sshadrin          #+#    #+#             */
/*   Updated: 2026/04/23 17:23:20 by sshadrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int i        = -1;
	int response = 0;
	int isMinus  = 0;

	while (str[++i])
	{
		if (i == 0 && str[i] == '-')
			isMinus++;
		else if (str[i] >= 48 && str[i] <= 57)
			response = ((response * 10) + str[i]) - '0';
		else
			break;
	}
	if (isMinus == 1)
		response = response * (-1);
	return response;
}

// int main () {
// 	const char str[] = "7123";

// 	int num = ft_atoi(str);
// 	int num_or = atoi(str);

// 	printf("%d\n", num);
// 	printf("%d\n", num_or);

// 	return 0;
// }