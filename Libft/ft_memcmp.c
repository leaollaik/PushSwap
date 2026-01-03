/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:58:38 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:14:53 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t			i;
	unsigned char	*f1;
	unsigned char	*f2;

	i = 0;
	if (n == 0)
		return (0);
	f1 = (unsigned char *)s1;
	f2 = (unsigned char *)s2;
	while (i < n - 1 && f1[i] == f2[i])
		i++;
	return (f1[i] - f2[i]);
}

// int	main(void)
// {
// 	char	s[] = {-128, 0, 127, 0};
// 	char	s2[] = {0, 0, 127, 0};
// 	char	sCpy[] = {-128, 0, 127, 0};

// 	printf("%d\n", ft_memcmp(s, s2, 0));
// 	// printf("%d\n", ft_memcmp(s2, s, 1));
// 	// printf("%d\n", ft_memcmp(s, sCpy, 4));
// 	// printf("%d\n", ft_memcmp(s, s2, 0));
// 	printf("%d\n", memcmp(s, s2, 0));
// }
