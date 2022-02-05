/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 11:16:39 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:46:01 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node* swap(t_node *root)
{
    t_node* next;
    t_node* prev;

    if (!root)
        return (0);

    next = root->next;
    prev = root->prev;
    
    root->next = next->next;
    root->prev = next;
    next->next->prev = root;
    
    next->next = root;
    next->prev = prev;

    prev->next = next;
    
    return (next);
}

t_node* rotate(t_node *root)
{
    if (!root)
        return (0);
    return (root->next);
}

t_node* reverse_rotate(t_node *root)
{
    if (!root)
        return (0);
    return (root->prev);
}
