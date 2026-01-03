/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_node_helpers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/17 19:22:06 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/26 18:23:41 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	stack_size(t_node *a)
{
	int	i;

	i = 0;
	while (a)
	{
		i++;
		a = a->next;
	}
	return (i);
}

t_node	*new_node(int value, int index)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->value = value;
	node->index = index;
	node->next = NULL;
	return (node);
}

void	lst_add_back(t_node **header, t_node *node)
{
	t_node	*temp;

	if (!header || !node)
		return ;
	if (!*header)
	{
		*header = node;
		return ;
	}
	temp = *header;
	while (temp->next)
		temp = temp->next;
	temp->next = node;
}
