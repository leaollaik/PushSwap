/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 21:25:54 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/10 14:49:05 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	*p;

	p = (unsigned char *)s;
	while (*p != '\0')
	{
		if (*p == (unsigned char)c)
			return ((char *)p);
		p++;
	}
	if ((unsigned char)c == '\0')
		return ((char *)p);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>
// int	main(void)
// {
// 	char	*s;

// 	s = "hello 	World!";
// 	printf("ft_strchr:%s\n", ft_strchr(s, '	'));
// 	printf("strchr:%s\n", strchr(s, '	'));
// }
