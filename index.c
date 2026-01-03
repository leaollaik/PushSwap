/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:29:46 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 19:42:55 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	find_bits(t_node *stack)
{
	int	i;
	int	max_num;

	max_num = stack_size(stack);
	i = 0;
	while (max_num > 0)
	{
		i++;
		max_num >>= 1;
	}
	return (i);
}
