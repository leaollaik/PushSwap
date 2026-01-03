/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 20:02:31 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/02 20:24:24 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	int	i;

	i = 0;
	if (!s || !f)
		return ;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}
// void fuc (unsigned int index, char *c)
// {
// 	index = 0 ;
// 	*c += 1 ;
// }

// int	main(void)
// {
// 	char str[] = "A b c d e f" ;

// 	ft_striteri(str, fuc);
// 	printf("%s", str);
// }
