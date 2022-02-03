/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dequeue.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/03 18:52:17 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/03 18:59:20 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* ft_sa(t_node *root_a)
{
    t_node* next;
    
    next = root_a->next;
    
    next->prev = root_a->prev;
    root_a->next = next->next;
    next->next = root_a;
    
}