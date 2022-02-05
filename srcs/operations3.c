/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:51:16 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 12:02:16 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* rra(t_node *root)
{
	if (!root)
		return (0);
	root = reverse_rotate(root);
	write(STANDART_OUTPUT, "rra\n", 4);
	return (root);
}

t_node* rrb(t_node *root)
{
	if (!root)
		return (0);
	root = reverse_rotate(root);
	write(STANDART_OUTPUT, "rrb\n", 4);
	return (root);
}

void	rrr(t_node **root_a, t_node **root_b)
{
	if (!(*root_a) || !(*root_b))
		return ;
	*root_a = reverse_rotate(*root_a);
	*root_b = reverse_rotate(*root_b);
	write(STANDART_OUTPUT, "rrr\n", 4);
}
