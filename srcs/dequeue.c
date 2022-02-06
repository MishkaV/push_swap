/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:55:25 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 18:33:07 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node  *get_new_node(int num)
{
    t_node  *node;
    
    node = malloc(sizeof(t_node));
    if (!node)
        return (0);
    node->next = node;
    node->prev = node;
    node->num = num;
    node->gen = 0;
    node->index = 0;
    return (node);
}

t_node  *push_front(t_node *root, t_node *new_node)
{
    if (!root)
        return (new_node);
    new_node->prev = root->prev;
    new_node->next = root;
    root->prev->next  = new_node;
    root->prev = new_node;

    return (new_node);
}

t_node  *push_back(t_node *root, t_node *new_node)
{
    if (!root)
        return (new_node);
    new_node->prev = root->prev;
    new_node->next = root;
    root->prev->next = new_node;
    root->prev = new_node;
    
    return (root);
}