/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 15:22:47 by achoukei          #+#    #+#             */
/*   Updated: 2025/12/28 19:43:40 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "Libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_node
{
	int				value;
	int				index;
	struct s_node	*next;
}					t_node;

typedef struct operations
{
	int				sa;
	int				sb;
	int				ss;
	int				pa;
	int				pb;
	int				ra;
	int				rb;
	int				rr;
	int				rra;
	int				rrb;
	int				rrr;
}					t_oper;

typedef struct arguments
{
	int				bench;
	int				strategy;
	int				*values;
	int				flaged;
	int				input_start;
	int				num_values;
	int				num_oper;
	t_oper			*oper;
}					t_args;

void				sx(t_node **x, int flag, t_args *args);
void				ss(t_node **a, t_node **b, t_args *args);
void				pa(t_node **a, t_node **b, t_args *args);
void				pb(t_node **a, t_node **b, t_args *args);
void				rx(t_node **a, int flag, t_args *args);
void				rr(t_node **a, t_node **b, t_args *args);
void				rrx(t_node **a, int flag, t_args *args);
void				rrr(t_node **a, t_node **b, t_args *args);
size_t				ft_strlen_arr(char **arr);
float				compute_disorder(t_node *stack);
void				radix(t_node **stack, t_args *args);
void				lst_add_back(t_node **header, t_node *node);
t_node				*new_node(int value, int index);
int					stack_size(t_node *a);
int					find_bits(t_node *stack);
void				free_str_arr(char **arr);
int					ft_strcmp(char *s1, char *s2);
void				new_args(t_args **args);
char				*one_line(char **argv, int i);
int					ft_isspace(char c);
size_t				ft_strlen_split(char **argv, int i);
int					parse_flag(char *flag, t_args *args);
int					*parse_values(char **argv, int i, t_args *args);
int					*parse(char **argv, t_args *args);
int					ft_strcmp(char *s1, char *s2);
int					valid_input(char *input);
size_t				ft_inputlen(char *input);
void				complex(t_node **stack, t_args *args);
void				new_oper(t_oper **oper);
void				free_args(t_args **args);
void				error_exit(t_args *args);
void				free_stack(t_node **a);
void				sort_values(int **c_v, int len);
int					*get_copy(int *v, int len);
int					get_index(int num, int *arr, int len);
t_node				*get_stack(int *values, t_args *args);
void				check_algo(t_node **stack, char **argv, t_args *args);
void				adaptive(t_node **stack, t_args *args);
void				print_oper(int flag, t_args *args);
void				simple_sort(t_node **a, t_args *args);
void				medium_sort(t_node **a, t_args *args);
void				adaptive_sort(t_node **a, t_args *args);
void				bench_print(t_args *args, float disorder, int strategy_id);
int					is_sorted(t_node *a);
int					find_pos_min_index(t_node *a);
int					find_pos_max_index(t_node *a);
void				rotate_a_to_pos(t_node **a, int pos, t_args *args);
void				rotate_b_to_pos(t_node **b, int pos, t_args *args);

#endif