/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 21:04:34 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 22:22:34 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_dequeue(t_node *root)
{
	t_node *begin;
	
	if (!root)
		return ;
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
}

int is_sorted_ascending(t_node* root)
{
    t_node *begin;

    begin = root;
	while (root->next != begin)
    {
        if (root->num > root->next->num)
            return (0);
        root = root->next;
    }
    return (1);
}

int	find_max(t_node* root)
{
	int		max;
	t_node*	begin;

	max = root->num;
	begin = root;
	while (root->next != begin)
	{
		if (root->num > max)
			max = root->num;
		root = root->next;
	}
	if (root->num > max)
		max = root->num;
	return (max);
}

int	find_min(t_node* root)
{
	int		min;
	t_node*	begin;

	if (!root)
		return (-1);
	min = root->num;
	begin = root;
	while (root->next != begin)
	{
		if (root->num < min)
			min = root->num;
		root = root->next;
	}
	if (root->num < min)
		min = root->num;
	return (min);
}
