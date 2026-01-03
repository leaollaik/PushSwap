#include "push_swap.h"

void	sx(t_node **x, int flag, t_args *args)
{
	t_node	*first;
	t_node	*second;

	if (!x || !*x || !(*x)->next)
		return ;
	first = *x;
	second = (*x)->next;
	first->next = second->next;
	second->next = first;
	*x = second;
	if (flag == 1)
	{
		write(1, "sa\n", 3);
		args->oper->sa++;
		args->num_oper++;
	}
	else if (flag == 2)
	{
		write(1, "sb\n", 3);
		args->oper->sb++;
		args->num_oper++;
	}
}

void	ss(t_node **a, t_node **b, t_args *args)
{
	if (!a || !b)
		return ;
	if ((*a && (*a)->next) || (*b && (*b)->next))
	{
		sx(a, 0, args);
		sx(b, 0, args);
		write(1, "ss\n", 3);
		args->oper->ss++;
		args->num_oper++;
	}
}

void	pa(t_node **a, t_node **b, t_args *args)
{
	t_node	*tmp;

	if (!b || !*b)
		return ;
	tmp = *b;
	*b = (*b)->next;
	tmp->next = *a;
	*a = tmp;
	write(1, "pa\n", 3);
	args->oper->pa++;
	args->num_oper++;
}

void	pb(t_node **a, t_node **b, t_args *args)
{
	t_node	*tmp;

	if (!a || !*a)
		return ;
	tmp = *a;
	*a = (*a)->next;
	tmp->next = *b;
	*b = tmp;
	write(1, "pb\n", 3);
	args->oper->pb++;
	args->num_oper++;
}
