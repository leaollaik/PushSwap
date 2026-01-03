/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/28 17:52:23 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 17:54:05 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*get_copy(int *v, int len)
{
	int	i;
	int	*value_copy;

	i = 0;
	value_copy = malloc(len * sizeof(int));
	while (i < len)
	{
		value_copy[i] = v[i];
		i++;
	}
	sort_values(&value_copy, len);
	return (value_copy);
}

int	get_index(int num, int *arr, int len)
{
	int	i;

	i = 0;
	while (i < len)
	{
		if (num == arr[i])
			return (i);
		i++;
	}
	return (-1);
}

t_node	*get_stack(int *values, t_args *args)
{
	int		*value_sorted;
	int		i;
	int		index;
	t_node	*head;

	head = NULL;
	i = 0;
	value_sorted = get_copy(values, args->num_values);
	while (i < args->num_values)
	{
		index = get_index(values[i], value_sorted, args->num_values);
		lst_add_back(&head, new_node(values[i], index));
		i++;
	}
	free(value_sorted);
	return (head);
}

void	free_stack(t_node **a)
{
	t_node	*tmp;

	while (a && *a)
	{
		tmp = (*a)->next;
		free(*a);
		*a = tmp;
	}
}

void	sort_values(int **c_v, int len)
{
	int	i;
	int	j;
	int	tmp;

	i = 0;
	while (i < len)
	{
		j = i + 1;
		while (j < len)
		{
			if ((*c_v)[i] > (*c_v)[j])
			{
				tmp = (*c_v)[i];
				(*c_v)[i] = (*c_v)[j];
				(*c_v)[j] = tmp;
			}
			j++;
		}
		i++;
	}
}
