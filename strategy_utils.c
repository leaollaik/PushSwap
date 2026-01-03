#include "push_swap.h"

int	is_sorted(t_node *a)
{
	while (a && a->next)
	{
		if (a->value > a->next->value)
			return (0);
		a = a->next;
	}
	return (1);
}

int	find_pos_min_index(t_node *a)
{
	int		pos;
	int		best_pos;
	int		best_idx;

	pos = 0;
	best_pos = 0;
	best_idx = 2147483647;
	while (a)
	{
		if (a->index < best_idx)
		{
			best_idx = a->index;
			best_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (best_pos);
}

int	find_pos_max_index(t_node *a)
{
	int		pos;
	int		best_pos;
	int		best_idx;

	pos = 0;
	best_pos = 0;
	best_idx = -2147483648;
	while (a)
	{
		if (a->index > best_idx)
		{
			best_idx = a->index;
			best_pos = pos;
		}
		pos++;
		a = a->next;
	}
	return (best_pos);
}

void	rotate_a_to_pos(t_node **a, int pos, t_args *args)
{
	int	size;

	size = stack_size(*a);
	if (size <= 1 || pos <= 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rx(a, 1, args);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrx(a, 1, args);
	}
}

void	rotate_b_to_pos(t_node **b, int pos, t_args *args)
{
	int	size;

	size = stack_size(*b);
	if (size <= 1 || pos <= 0)
		return ;
	if (pos <= size / 2)
	{
		while (pos-- > 0)
			rx(b, 2, args);
	}
	else
	{
		pos = size - pos;
		while (pos-- > 0)
			rrx(b, 2, args);
	}
}
