/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:18:19 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:58:04 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATIONS_H
# define OPERATIONS_H

t_node*	sa(t_node *root);
t_node*	sb(t_node *root);
t_node*	pa(t_node *root_a, t_node **root_b);
t_node*	pb(t_node *root_b, t_node **root_a);
t_node*	ra(t_node *root);
t_node*	rb(t_node *root);
void	rr(t_node **root_a, t_node **root_b);
t_node* rra(t_node *root);
t_node* rrb(t_node *root);
void	rrr(t_node **root_a, t_node **root_b);

#endif