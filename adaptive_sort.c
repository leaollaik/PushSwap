#include "push_swap.h"

static void	low_disorder_sort(t_node **a, t_args *args)
{
	t_node	*b;
	int		n;
	int		i;

	b = NULL;
	n = stack_size(*a);
	i = 0;
	while (i < n && !is_sorted(*a))
	{
		if ((*a)->next && (*a)->value > (*a)->next->value)
		{
			sx(a, 1, args);
			pb(a, &b, args);
		}
		else
			rx(a, 1, args);
		i++;
	}
	while (b)
		pa(a, &b, args);
	if (!is_sorted(*a))
		simple_sort(a, args);
}

void	adaptive_sort(t_node **a, t_args *args)
{
	float	disorder;

	if (!a || !*a)
		return ;
	disorder = compute_disorder(*a);
	if (disorder < 0.2f)
		low_disorder_sort(a, args);
	else if (disorder < 0.5f)
		medium_sort(a, args);
	else
		complex(a, args);
}
