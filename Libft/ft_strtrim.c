/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/30 21:25:19 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 18:59:49 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_start(char const *s, char const *set)
{
	int	start;

	start = 0;
	while (s[start] && ft_strchr(set, s[start]))
		start++;
	return (start);
}

static int	get_end(char const *s, char const *set, size_t s_len)
{
	int	end;

	end = s_len;
	while (end > 0 && ft_strchr(set, s[end - 1]))
		end--;
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	s1_len;
	int		start;
	int		end;

	if (!s1 || !set)
		return (NULL);
	s1_len = ft_strlen(s1);
	start = get_start(s1, set);
	end = get_end(s1, set, s1_len);
	if (start >= end)
		return (ft_strdup(""));
	return (ft_substr(s1, start, end - start));
}

// int	main(void)
// {
// 	char	str[] = "aacalihellocccccccc";
// 	char	set[] = "abc";

// 	printf("%s", ft_strtrim(str, set));
// }
