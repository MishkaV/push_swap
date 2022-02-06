/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:52:17 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 19:40:01 by jbenjy           ###   ########.fr       */
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
	t_node* node_b;

	if (!(*root_b))
		return (root_a);
	node_b = *root_b;
	*root_b = (*root_b)->next;
	(*root_b)->prev = node_b->prev;
	node_b->prev->next = *root_b;
	
	root_a = push_front(root_a, node_b);
	ft_putstr_fd("pa\n", STANDART_OUTPUT);
	return (root_a);
}

t_node* pb(t_node *root_b, t_node **root_a)
{
	t_node* node_a;

	if (!(*root_a))
		return (root_b);
	node_a = *root_a;
	*root_a = (*root_a)->next;
	(*root_a)->prev = node_a->prev;
	node_a->prev->next = *root_a;
	
	root_b = push_front(root_b, node_a);
	ft_putstr_fd("pb\n", STANDART_OUTPUT);
	return (root_b);
}
