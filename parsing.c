/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/22 16:21:49 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 18:51:34 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <limits.h>

static int	cmp_int(const void *a, const void *b)
{
	const int	x = *(const int *)a;
	const int	y = *(const int *)b;

	if (x < y)
		return (-1);
	if (x > y)
		return (1);
	return (0);
}

static int	parse_atoi(const char *s, t_args *args)
{
	long	res;
	int		sign;
	int		i;

	if (!s || *s == '\0')
		error_exit(args);
	i = 0;
	sign = 1;
	if (s[i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			sign = -1;
		i++;
	}
	if (s[i] == '\0')
		error_exit(args);
	res = 0;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			error_exit(args);
		res = (res * 10) + (s[i] - '0');
		if ((sign == 1 && res > INT_MAX) || (sign == -1 && -res < INT_MIN))
			error_exit(args);
		i++;
	}
	return ((int)(res * sign));
}

static void	check_duplicates(int *values, int n, t_args *args)
{
	int	*cpy;
	int	i;

	if (n <= 1)
		return ;
	cpy = malloc(sizeof(int) * n);
	if (!cpy)
		error_exit(args);
	i = 0;
	while (i < n)
	{
		cpy[i] = values[i];
		i++;
	}
	qsort(cpy, n, sizeof(int), cmp_int);
	i = 1;
	while (i < n)
	{
		if (cpy[i] == cpy[i - 1])
		{
			free(cpy);
			error_exit(args);
		}
		i++;
	}
	free(cpy);
}

int	parse_flag(char *flag, t_args *args)
{
	if (flag)
	{
		if (ft_strcmp(flag, "--simple") == 0 && args->strategy == 0)
			args->strategy = 1;
		else if (ft_strcmp(flag, "--medium") == 0 && args->strategy == 0)
			args->strategy = 2;
		else if (ft_strcmp(flag, "--complex") == 0 && args->strategy == 0)
			args->strategy = 3;
		else if (ft_strcmp(flag, "--adaptive") == 0 && args->strategy == 0)
			args->strategy = 0;
		else if (ft_strcmp(flag, "--bench") == 0 && args->bench == 0)
			args->bench = 1;
		else
			return (0);
	}
	return (1);
}

int	*parse_values(char **argv, int i, t_args *args)
{
	char	*input;
	int		*values;
	char	**split;
	int		j;
	int		len;

	j = 0;
	if (argv[i][0] == '\0')
		error_exit(args);
	input = one_line(argv, i);
	if (!valid_input(input))
	{
		free(input);
		error_exit(args);
	}
	len = ft_inputlen(input);
	values = malloc(sizeof(int) * len);
	if (!values)
	{
		free(input);
		error_exit(args);
	}
	(*args).num_values = len;
	split = ft_split(input, ' ');
	free(input);
	while (split[j])
	{
		values[j] = parse_atoi(split[j], args);
		j++;
	}
	check_duplicates(values, len, args);
	free_str_arr(split);
	return (values);
}

int	*parse(char **argv, t_args *args)
{
	char	*flag_1;
	char	*flag_2;
	int		i;

	i = 0;
	flag_1 = NULL;
	flag_2 = NULL;
	while (argv[++i])
	{
		if ((ft_strncmp(argv[i], "--", 2) == 0) && i == 1)
			flag_1 = argv[i];
		else if ((ft_strncmp(argv[i], "--", 2) == 0) && i == 2)
			flag_2 = argv[i];
		else
			break ;
		args->input_start++;
	}
	if (flag_1)
		if (!parse_flag(flag_1, args))
			error_exit(args);
	if (flag_2)
		if (!parse_flag(flag_2, args))
			error_exit(args);
	return (parse_values(argv, i, args));
}

int	valid_input(char *input)
{
	int	i;

	i = 0;
	while (input[i])
	{
		if (!ft_isspace(input[i]))
		{
			if (input[i] == '-' || input[i] == '+')
				i++;
			if (!ft_isdigit(input[i]))
				return (0);
		}
		i++;
	}
	return (1);
}
