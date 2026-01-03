/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 19:30:13 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/07 00:00:51 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	int		i;
	int		s_len;
	char	*dup;

	if (s == 0)
		return (malloc(0));
	s_len = ft_strlen(s);
	i = 0;
	dup = (char *)malloc(sizeof(char) * s_len + 1);
	if (dup == 0)
		return (0);
	while (i < s_len && s[i] != '\0')
	{
		dup[i] = s[i];
		i++;
	}
	dup[i] = '\0';
	return (dup);
}

// int	main(void)
// {
// 	char	s[] = "";

// 	printf("%s", ft_strdup(s));
// }
