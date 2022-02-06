/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:52:17 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 20:56:01 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* sa(t_node *root)
{
	if (!root)
		return (0);
	root = swap(root);
	ft_putstr_fd("sa\n", STANDART_OUTPUT);
	return (root);
}

t_node* sb(t_node *root)
{
	if (!root)
		return (0);
	root = swap(root);
	ft_putstr_fd("sb\n", STANDART_OUTPUT);
	return (root);
}

t_node* pa(t_node *root_a, t_node **root_b)
{
	t_node* node;
	t_node* begin_b;
	
	if (!(*root_b))
		return (root_a);
	
	begin_b = *root_b;
	node = get_new_node(begin_b->num);
	
	begin_b->prev->next = begin_b->next;
	begin_b->next->prev = begin_b->prev;
	if (begin_b == begin_b->next)
		begin_b = 0;
	else
		begin_b = begin_b->next;
	free(*root_b);
	*root_b = begin_b;
	
	root_a = push_front(root_a, node);
	ft_putstr_fd("pa\n", STANDART_OUTPUT);
	return (root_a);
}

t_node* pb(t_node *root_b, t_node **root_a)
{
	t_node* node;
	t_node* begin_a;

	if (!(*root_a))
		return (root_b);
	
	begin_a = *root_a;
	node = get_new_node(begin_a->num);

	begin_a->prev->next = begin_a->next;
	begin_a->next->prev = begin_a->prev;
	if (begin_a == begin_a->next)
		begin_a = 0;
	else
		begin_a = begin_a->next;
	free(*root_a);
	*root_a = begin_a;
	
	root_b = push_front(root_b, node);
	ft_putstr_fd("pb\n", STANDART_OUTPUT);
	return (root_b);
}
