/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/23 18:06:22 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 18:51:17 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (s1[i] - s2[i]);
}

void	new_args(t_args **args)
{
	t_oper	*oper;

	oper = malloc(sizeof(t_oper));
	new_oper(&oper);
	(*args)->bench = 0;
	(*args)->strategy = 0;
	(*args)->flaged = 0;
	(*args)->num_values = 0;
	(*args)->input_start = 1;
	(*args)->num_oper = 0;
	(*args)->oper = oper;
	(*args)->values = NULL;
}

void	new_oper(t_oper **oper)
{
	(*oper)->pa = 0;
	(*oper)->pb = 0;
	(*oper)->sa = 0;
	(*oper)->sb = 0;
	(*oper)->ss = 0;
	(*oper)->ra = 0;
	(*oper)->rb = 0;
	(*oper)->rr = 0;
	(*oper)->rra = 0;
	(*oper)->rrb = 0;
	(*oper)->rrr = 0;
}

void	free_args(t_args **args)
{
	free((*args)->oper);
	free((*args));
}

void	error_exit(t_args *args)
{
	write(2, "Error\n", 6);
	free_args(&args);
	exit(1);
}
