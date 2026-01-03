/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 18:40:27 by achoukei          #+#    #+#             */
/*   Updated: 2025/10/30 18:07:51 by achoukei         ###   ########.fr       */
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

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	src_len = ft_strleng(src);
	i = 0;
	if (size == 0)
		return (src_len);
	while (src[i] != 0 && (i < (size - 1)))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_len);
}

// int	main(void)
// {
// 	char	s[] = "hello";
// 	char	d[] = "hi";

// 	// printf("strlcpy:%zu\n", strlcpy(d,s,5));
// 	printf("ft_strlcpy:%zu\n", ft_strlcpy(d, s, 5));
// 	printf("%s\n", d);
// }
