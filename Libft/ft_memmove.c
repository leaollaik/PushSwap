/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 16:24:32 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:15:04 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*ft_memcpyy(void *dest, const void *src, size_t n)
{
	unsigned char	*p;
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *)src;
	p = (unsigned char *)dest;
	while (i < n)
	{
		p[i] = (unsigned char)d[i];
		i++;
	}
	return (p);
}

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	int					i;
	const unsigned char	*s;
	unsigned char		*d;

	s = (const unsigned char *)src;
	d = (unsigned char *)dest;
	i = n - 1;
	if (s < d && (s + n - 1) >= d)
	{
		while (i >= 0)
		{
			d[i] = s[i];
			i--;
		}
	}
	else
		d = (unsigned char *)ft_memcpyy(d, s, n);
	return (d);
}
// int main()
// {
// 	char s[10] = "abcdefg";
// 	printf("%s",(char *)ft_memmove(s,s-2 ,5));
// 	// printf("%s",(char *)memmove(s,s-2 ,5));
// }
