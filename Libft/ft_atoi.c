/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 15:11:03 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/04 21:23:23 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	start_index(char *nptr)
{
	int	i;

	i = 0;
	while (nptr[i] == ' ' || (nptr[i] >= 9 && nptr[i] <= 13))
		i++;
	return (i);
}

int	ft_atoi(const char *nptr)
{
	int		result;
	int		i;
	char	*str;
	int		sign;

	sign = 1;
	str = (char *)nptr;
	if (ft_strncmp(str, "-2147483648", 12) == 0)
		return (-2147483648);
	i = start_index(str);
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	result = 0;
	if (*str == '\0')
		return (0);
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10 + (str[i] % 48));
		i++;
	}
	result *= sign;
	return (result);
}
