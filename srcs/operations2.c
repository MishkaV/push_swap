/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:44:55 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:57:57 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* ra(t_node *root)
{
	root = rotate(root);
	write(STANDART_OUTPUT, "ra\n", 3);
	return (root);
}

t_node* rb(t_node *root)
{
	root = rotate(root);
	write(STANDART_OUTPUT, "rb\n", 3);
	return (root);
}

void	rr(t_node **root_a, t_node **root_b)
{
	*root_a = rotate(*root_a);
	*root_b = rotate(*root_b);
	write(STANDART_OUTPUT, "rr\n", 3);
}