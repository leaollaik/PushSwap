/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:39:42 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:14:56 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *)src;
	p = (unsigned char *)dest;
	if (n == 0)
		return (p);
	while (i < n)
	{
		p[i] = (unsigned char)d[i];
		i++;
	}
	return (p);
}

// int	main(void)
// {
// 	char	dest[100];

// 	memset(dest, 'A', 100);
// 	// char src[] = {0, 0};
// 	printf("%s", (char *)ft_memcpy(dest, "Coco", 4));
// 	return (0);
// }
