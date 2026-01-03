#include "push_swap.h"

float	compute_disorder(t_node *stack)
{
	int		mistakes;
	int		total_pairs;
	t_node	*first_loop;
	t_node	*second_loop;

	if (!stack || !stack->next)
		return (0.0f);
	first_loop = stack;
	mistakes = 0;
	total_pairs = 0;
	while (first_loop)
	{
		second_loop = first_loop->next;
		while (second_loop)
		{
			total_pairs++;
			if (first_loop->value > second_loop->value)
				mistakes++;
			second_loop = second_loop->next;
		}
		first_loop = first_loop->next;
	}
	if (total_pairs == 0)
		return (0.0f);
	return ((float)mistakes / (float)total_pairs);
}

static void	run_strategy(t_node **a, t_args *args, int *used_strategy)
{
	if (args->strategy == 1)
	{
		*used_strategy = 1;
		simple_sort(a, args);
	}
	else if (args->strategy == 2)
	{
		*used_strategy = 2;
		medium_sort(a, args);
	}
	else if (args->strategy == 3)
	{
		*used_strategy = 3;
		complex(a, args);
	}
	else
	{
		*used_strategy = 0;
		adaptive_sort(a, args);
	}
}

int	main(int argc, char **argv)
{
	t_args	*args;
	int		*values;
	t_node	*stack;
	float	disorder;
	int		used_strategy;

	stack = NULL;
	args = malloc(sizeof(t_args));
	if (!args)
		return (1);
	new_args(&args);
	if (argc <= 1)
		return (0);
	values = parse(argv, args);
	stack = get_stack(values, args);
	free(values);
	disorder = compute_disorder(stack);
	used_strategy = 0;
	if (!is_sorted(stack))
		run_strategy(&stack, args, &used_strategy);
	if (args->bench)
		bench_print(args, disorder, used_strategy);
	free_stack(&stack);
	free_args(&args);
	return (0);
}
