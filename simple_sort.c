#include "push_swap.h"

void	simple_sort(t_node **a, t_args *args)
{
	t_node	*b;
	int		pos;

	b = NULL;
	while (*a && !is_sorted(*a))
	{
		pos = find_pos_min_index(*a);
		rotate_a_to_pos(a, pos, args);
		pb(a, &b, args);
	}
	while (b)
		pa(a, &b, args);
}
