/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/01 16:21:16 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 19:03:12 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (count);
}

static int	word_len(char const *s, char c)
{
	int	len;

	len = 0;
	while (s[len] && s[len] != c)
		len++;
	return (len);
}

static char	**free_str(char ***arr, int i)
{
	while (i > 0)
		free((*arr)[--i]);
	free(*arr);
	*arr = NULL;
	return (NULL);
}

char	**ft_split(char const *s, char c)
{
	char	**arr;
	int		i;
	int		j;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	arr = malloc(sizeof(char *) * (words + 1));
	if (!arr)
		return (NULL);
	i = 0;
	j = 0;
	while (i < words)
	{
		while (s[j] == c)
			j++;
		arr[i] = ft_substr(s, j, word_len(&s[j], c));
		if (!arr[i])
			return (free(arr), free_str(&arr, i));
		j += word_len(&s[j], c);
		i++;
	}
	arr[i] = NULL;
	return (arr);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include "libft.h"

// int	main(void)
// {
// 	char	*s = NULL;
// 	char	c;
// 	char	**arr;
// 	int		i;

// 	c = ' ';
// 	arr = ft_split(s, c);
// 	if (!arr)
// 		return (1);

// 	i = 0;
// 	while (arr[i])
// 	{
// 		printf("%s\n", arr[i]);
// 		i++;
// 	}

// 	i = 0;
// 	while (arr[i])
// 	{
// 		free(arr[i]);
// 		i++;
// 	}
// 	free(arr);

// 	return (0);
// }
