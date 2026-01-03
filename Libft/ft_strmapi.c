/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/02 15:31:09 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/03 15:14:27 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		s_len;
	int		i;
	char	*str;

	i = 0;
	if (!s || !f)
		return (0);
	s_len = ft_strlen(s);
	str = (char *)malloc(sizeof(char) * s_len + 1);
	if (str == 0)
		return (0);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}

// char	func(unsigned int index, char c)
// {
// 	index = 0;
// 	return (c + 1);
// }

// int	main(void)
// {
// 	char	str[] = "A b c d e f";
// 	char	*new_s;

// 	new_s = ft_strmapi(str, func);
// 	printf("%s", new_s);
// }
