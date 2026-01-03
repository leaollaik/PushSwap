/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/28 16:31:44 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 20:13:02 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "stdlib.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*p;
	size_t			i;

	p = (unsigned char *)s;
	i = 0;
	while (i < n)
	{
		p[i] = 0;
		i++;
	}
}

// int	main(void)
// {
// 	int	arr[6] = {1, 6, 87, 8, 5, 0};
// 	int	arr1[6] = {1, 6, 87, 8, 5, 0};

// 	printf("\nBefore ft_bzero:\n");
// 	for (int i = 0; i < 6; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n");
// 	ft_bzero(arr, sizeof(arr));
// 	printf("After ft_bzero:\n");
// 	for (int i = 0; i < 6; i++)
// 		printf("%d ", arr[i]);
// 	printf("\n\n");

// 	printf("\nBefore bzero:\n");
// 	for (int i = 0; i < 6; i++)
// 		printf("%d ", arr1[i]);
// 	printf("\n");
// 	bzero(arr1, sizeof(arr1));
// 	printf("After bzero:\n");
// 	for (int i = 0; i < 6; i++)
// 		printf("%d ", arr1[i]);
// 	printf("\n\n");
// }
