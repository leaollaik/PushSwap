/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 02:19:38 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:15:58 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;
	char	*b;

	i = 0;
	b = (char *)big;
	if (*little == '\0')
		return (b);
	while (b[i] != '\0' && i < len)
	{
		j = 0;
		while (b[i + j] == little[j] && little[j] != '\0' && (i + j) < len)
		{
			if (little[j + 1] == '\0')
				return (b + i);
			j++;
		}
		i++;
	}
	return (0);
}

// int	main(void)
// {
// 	char	s1[] = "Foo Bar Baz";
// 	char	s2[] = "\0";
// 	int		n;

// 	n = 11;
// 	printf("ft_strnstr:%s\n", ft_strnstr(s1, s2, n));
// 	// printf("strnstr:%d\n", strnstr(s1, s2, n));
// }
