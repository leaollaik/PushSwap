/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: achoukei <achoukei@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 06:34:39 by achoukei          #+#    #+#             */
/*   Updated: 2025/11/08 18:41:49 by achoukei         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}

// int	main(void)
// {
// 	int		a;
// 	int		b;
// 	int		c;
// 	int		d;
// 	t_list	*node1;
// 	t_list	*node2;
// 	t_list	*node3;
// 	t_list	*node4;
// 	t_list	*head;
// 	t_list	*temp;
// 	t_list	*tmp;

// 	a = 1;
// 	b = 2;
// 	c = 3;
// 	d = 4;
// 	node1 = ft_lstnew(&a);
// 	node2 = ft_lstnew(&b);
// 	node3 = ft_lstnew(&c);
// 	node4 = ft_lstnew(&d);
// 	head = NULL;
// 	ft_lstadd_front(&head, node3);
// 	ft_lstadd_front(&head, node2);
// 	ft_lstadd_front(&head, node1);
// 	ft_lstadd_back(&head, node4);
// 	temp = head;
// 	while (temp)
// 	{
// 		printf("%d\n", *(int *)temp->content);
// 		temp = temp->next;
// 	}
// 	printf("The size of the list is:%d\n", ft_lstsize(head));
// 	printf("The last nod.e contains:%d\n", *((int *)ft_lstlast(head)->content));
// 	while (head)
// 	{
// 		tmp = head->next;
// 		free(head);
// 		head = tmp;
// 	}
// }
