/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 20:01:54 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/06 23:11:49 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*arr;
	size_t	i;
	size_t	total;

	total = 0;
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	total = nmemb * size;
	if (size != 0 && total / size != nmemb)
		return (0);
	i = 0;
	arr = (void *)malloc(nmemb * size);
	if (arr == NULL)
		return (0);
	while (i < nmemb * size)
	{
		((char *)arr)[i] = 0;
		i++;
	}
	return (arr);
}

// int main()
// {
// 	char *s, *ss ;
// 	int	size = 5;
// 	int	nmemb = 5;
// 	s = (char *)ft_calloc(nmemb,size);
// 	ss = calloc(nmemb, size);
// 	printf("%s", s);
// 	printf("%s", ss);
// 	free(s);
// 	free(ss);
// }
