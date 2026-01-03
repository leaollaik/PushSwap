/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   complex.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/13 20:21:51 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 19:45:33 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	radix_sort(t_node **stack_a, t_args *args)
{
	t_node	*stack_b;
	int		i;
	int		max_bits;
	int		size;

	max_bits = find_bits(*stack_a);
	i = -1;
	stack_b = NULL;
	while (++i < max_bits)
	{
		size = stack_size(*stack_a);
		while (size--)
		{
			if (((*stack_a)->index >> i) & 1)
				rx(stack_a, 1, args);
			else
				pb(stack_a, &stack_b, args);
		}
		while (stack_b)
			pa(stack_a, &stack_b, args);
	}
}

void	radix(t_node **stack_a, t_args *args)
{
	radix_sort(stack_a, args);
}

void	complex(t_node **stack_a, t_args *args)
{
	radix(stack_a, args);
}
