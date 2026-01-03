/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 19:50:13 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:15:38 by achoukei         ###   ########.fr       */
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

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	src_len;
	size_t	dst_len;

	src_len = ft_strleng(src);
	dst_len = ft_strleng(dst);
	if (dst_len >= size)
		return (src_len + size);
	i = dst_len;
	j = 0;
	if (size > 0)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			i++;
			j++;
		}
		dst[i] = '\0';
	}
	return (dst_len + src_len);
}
// int	main(void)
// {
// 	char	s[] = "hello";
// 	char	d[] = "hi";

// 	printf("strlcat:%zu\n", strlcat(d, s, 0));
// 	printf("ft_strlcat:%zu\n", ft_strlcat(d, s, 0));
// 	printf("%s\n", d);
// }
