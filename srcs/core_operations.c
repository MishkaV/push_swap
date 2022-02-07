/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:16:39 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 21:58:24 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*swap(t_node *root)
{
	t_node	*next;
	t_node	*prev;

	if (!root)
		return (0);
	next = root->next;
	prev = root->prev;
	prev->next = next;
	next->prev = prev;
	root->next = next->next;
	next->next = root;
	root->prev = next;
	root->next->prev = root;
	return (next);
}

t_node	*rotate(t_node *root)
{
	if (!root)
		return (0);
	return (root->next);
}

t_node	*reverse_rotate(t_node *root)
{
	if (!root)
		return (0);
	return (root->prev);
}
