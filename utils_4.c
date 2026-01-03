/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_4.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:55:05 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 17:56:00 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	ft_inputlen(char *input)
{
	int		i;
	size_t	count;

	count = 0;
	i = 0;
	while (input[i])
	{
		if ((ft_isspace(input[i]) && !ft_isspace(input[i + 1]))
			|| (!ft_isspace(input[i]) && input[i + 1] == '\0'))
			count++;
		i++;
	}
	return (count);
}

size_t	ft_strlen_split(char **argv, int i)
{
	int	j;
	int	count;

	count = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!ft_isspace(argv[i][j]))
				count++;
			j++;
		}
		i++;
	}
	count = (count * 2);
	return (count);
}

int	ft_isspace(char c)
{
	if (c == ' ' || (c >= 9 && c <= 13))
		return (1);
	return (0);
}

char	*one_line(char **argv, int i)
{
	char	*line;
	int		j;
	int		k;

	line = malloc(ft_strlen_split(argv, i) + 1);
	k = 0;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if (!ft_isspace(argv[i][j]))
			{
				line[k++] = argv[i][j++];
				if ((ft_isspace(argv[i][j]) || argv[i][j] == '\0'))
					line[k++] = ' ';
			}
			else
				j++;
		}
		i++;
	}
	line[k] = '\0';
	return (line);
}
