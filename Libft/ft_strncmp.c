/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:05:25 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:15:51 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] != '\0' && s1[i] == s2[i] && (i < n - 1))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

// int	main(void)
// {
// 	char			s1[] = " ";
// 	char			s2[] = "";
// 	unsigned int	n;

// 	n = 5;
// 	printf("ft_strncmp:%d\n", ft_strncmp(s1, s2, n));
// 	printf("strncmp:%d\n", strncmp(s1, s2, n));
// }
