/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:04:34 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:40:32 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_dequeu(t_node *root)
{
    t_node *begin;

    begin = root;
    ft_putstr_fd("\n--------------------------------------\n", STANDART_OUTPUT);
    ft_putstr_fd("Dequeu:\n", STANDART_OUTPUT);
    while (root->next != begin)
    {
        ft_putnbr_fd(root->num, STANDART_OUTPUT);
        ft_putstr_fd("\n", STANDART_OUTPUT);
        root = root->next;
    }
    ft_putnbr_fd(root->num, STANDART_OUTPUT);
    ft_putstr_fd("\n--------------------------------------\n", STANDART_OUTPUT);
}

void    clean_dequeu(t_node *root)
{
    t_node *begin;
    t_node *next;

    begin = root;

    if (!root)
        return ;
    
    while (root->next != begin)
    {
        next = root->next;
        free(root);
        root = next;
    }
    free(root);
    ft_putstr_fd("\nCleaning dequeue is complete\n", STANDART_OUTPUT); 
}