#include "push_swap.h"

void	rx(t_node **a, int flag, t_args *args)
{
	t_node	*first;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	first = *a;
	*a = (*a)->next;
	first->next = NULL;
	last = *a;
	while (last->next)
		last = last->next;
	last->next = first;
	if (flag == 1)
	{
		write(1, "ra\n", 3);
		args->oper->ra++;
		args->num_oper++;
	}
	else if (flag == 2)
	{
		write(1, "rb\n", 3);
		args->oper->rb++;
		args->num_oper++;
	}
}

void	rr(t_node **a, t_node **b, t_args *args)
{
	if (!a || !b)
		return ;
	if ((*a && (*a)->next) || (*b && (*b)->next))
	{
		rx(a, 0, args);
		rx(b, 0, args);
		write(1, "rr\n", 3);
		args->oper->rr++;
		args->num_oper++;
	}
}

void	rrx(t_node **a, int flag, t_args *args)
{
	t_node	*prev;
	t_node	*last;

	if (!a || !*a || !(*a)->next)
		return ;
	prev = NULL;
	last = *a;
	while (last->next)
	{
		prev = last;
		last = last->next;
	}
	prev->next = NULL;
	last->next = *a;
	*a = last;
	if (flag == 1)
	{
		write(1, "rra\n", 4);
		args->oper->rra++;
		args->num_oper++;
	}
	else if (flag == 2)
	{
		write(1, "rrb\n", 4);
		args->oper->rrb++;
		args->num_oper++;
	}
}

void	rrr(t_node **a, t_node **b, t_args *args)
{
	if (!a || !b)
		return ;
	if ((*a && (*a)->next) || (*b && (*b)->next))
	{
		rrx(a, 0, args);
		rrx(b, 0, args);
		write(1, "rrr\n", 4);
		args->oper->rrr++;
		args->num_oper++;
	}
}
