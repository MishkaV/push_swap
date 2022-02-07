/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:44:53 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 20:55:20 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_smaller_element_detection(t_node *root, int to_save, int num, int len)
{
	t_node* curr;
	int     i;

    i = 0;
	curr = root;
	while (i < len)
	{
		if (num < curr->num && curr->num < to_save)
			return (1);
		curr = curr->next;
        i++;
	}
    return (0);
}

static void	ft_help_finding_place(t_all* all, t_node* root_b, int *to_do, int *to_save)
{
    int i;

    i = 0;
	while (i < all->len_a)
	{
		*to_save = all->root_a->num;
		if (root_b->num <= all->root_a->num)
            break ;
		(*to_do)++;
		if (root_b->num < all->root_a->next->num)
			break ;
		all->root_a = all->root_a->next;
        i++;
	
	}
	if (ft_smaller_element_detection(all->root_a, *to_save, root_b->num, all->len_a))
		while (i < all->len_a)
		{
			if (all->root_a->num > root_b->num && *to_save > all->root_a->num)
				break ;
			all->root_a = all->root_a->next;
			(*to_do)++;
            i++;
		}
}


static int  ft_finding_place(t_all* all, t_node* root_b, t_steps *steps, int num)
{
	int to_do;
	int to_save;

	to_do = 0;
	to_save = 0;
	ft_help_finding_place(all, root_b, &to_do, &to_save);
	if (all->root_a->rotate == -1)
		to_do = all->len_a - to_do;
	if (num <= to_do + root_b->step && num != -1)
		return (num);
    else
	{
		steps->dest_a = all->root_a->rotate;
		steps->count_a = to_do;
		steps->dest_b = root_b->rotate;
		steps->count_b = root_b->step;
		return (to_do + root_b->step);
	}
}

void	ft_minimum_insertion_steps(t_all* all, t_steps *steps)
{
    int		less_tick;
	t_node* first_a;
	t_node* first_b;
    int     i;
    int     len_b;

	i = 0;
    less_tick = -1;
    len_b = all->len_b;
	first_a = all->root_a;
	first_b = all->root_b;
	while (i < len_b)
	{
		less_tick = ft_finding_place(all, all->root_b, steps, less_tick);
		all->root_b = all->root_b->next;
		all->root_a = first_a;
        i++;
	}
	all->root_b = first_b;
}

int		ft_count_to_min(t_node *root, int num, int len)
{
	int i;

	i = 0;
	while (i < len)
	{
		if (root->num == num)
			return (i);
		root = root->next;
		i++;
	}
	return (i);
}
