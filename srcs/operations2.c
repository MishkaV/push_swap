/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:44:55 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 19:40:35 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* ra(t_node *root)
{
	if (!root)
		return (0);
	root = rotate(root);
	ft_putstr_fd("ra\n", STANDART_OUTPUT);
	return (root);
}

t_node* rb(t_node *root)
{
	if (!root)
		return (0);
	root = rotate(root);
	ft_putstr_fd("rb\n", STANDART_OUTPUT);
	return (root);
}

void	rr(t_node **root_a, t_node **root_b)
{
	if (!(*root_a) || !(*root_b))
		return ;
	*root_a = rotate(*root_a);
	*root_b = rotate(*root_b);
	ft_putstr_fd("rr\n", STANDART_OUTPUT);
}