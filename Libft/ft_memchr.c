/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:25:59 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:14:49 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*p;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		if (*p == (c % 128))
			return (p);
		i++;
		p++;
	}
	if (!(c % 128) && i > 0)
		return (p);
	return (0);
}

// int	main(void)
// {
// 	char s[] = {0, 1, 2 ,3 ,4 ,5};
// 	char	c;
// 	size_t	n;

// 	n = 0;
// 	c = 0;
// 	printf("ft_memchr:%s\n", (char *)ft_memchr(s, c, n));
// 	printf("memchr:%s\n", (char *)memchr(s, c, n));
// }
