/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 23:14:40 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/10 14:53:45 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_strleng(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*ft_strrchr(const char *s, int c)
{
	unsigned char	*p;
	int				s_len;
	int				i;

	p = (unsigned char *)s;
	s_len = ft_strleng(s);
	i = s_len;
	while (i >= 0)
	{
		if (p[i] == (unsigned char)c)
			return ((char *)p + i);
		i--;
	}
	if ((unsigned char)(c) == '\0')
		return ((char *)p + s_len);
	return (NULL);
}
// #include <stdio.h>
// #include <string.h>

// int	main(void)
// {
// 		char	s[] = {'t', 'r', 'i', 'p', (char)255, 'u', 't', 'i', 'l', 'l',
// 			0};

// 	printf("ft_strchr:%s\n", ft_strrchr(s, '	'));
// 	printf("strchr:%s\n", strrchr(s, '	'));
// }
