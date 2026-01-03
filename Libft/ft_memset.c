/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/27 18:02:11 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:15:13 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = c;
		i++;
	}
	return (s);
}

// int main()
// {
// 	int arr[] = {2, 2, 3, 4, 5, 6, 7, 8, 9};
// 	int *res ;
// 	res = ft_memset(arr, 0, -1);
// 	res = memset(arr, 2, 4);
// 	for (int i = 0; i < 20; i++) {
//         printf("%d,", arr[i]);
//     }
// }
