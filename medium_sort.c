#include "push_swap.h"

static int	sqrt_ceil_int(int n)
{
	long	r;

	if (n <= 0)
		return (0);
	r = 1;
	while (r * r < (long)n)
		r++;
	return ((int)r);
}

static void	push_chunks_to_b(t_node **a, t_node **b, t_args *args)
{
	int	n;
	int	chunk;
	int	limit;
	int	i;

	n = stack_size(*a);
	chunk = sqrt_ceil_int(n);
	limit = chunk;
	i = 0;
	while (*a)
	{
		if ((*a)->index < limit)
		{
			pb(a, b, args);
			i++;
			if (*b && (*b)->index < limit - (chunk / 2))
				rx(b, 2, args);
			if (i >= limit && limit < n)
				limit += chunk;
		}
		else
			rx(a, 1, args);
	}
}

static void	pull_back_to_a(t_node **a, t_node **b, t_args *args)
{
	int	pos;

	while (*b)
	{
		pos = find_pos_max_index(*b);
		rotate_b_to_pos(b, pos, args);
		pa(a, b, args);
	}
}

void	medium_sort(t_node **a, t_args *args)
{
	t_node	*b;

	b = NULL;
	if (!a || !*a || is_sorted(*a))
		return ;
	push_chunks_to_b(a, &b, args);
	pull_back_to_a(a, &b, args);
}
