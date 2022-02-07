/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:44:53 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 21:20:12 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  search_min_num(t_node *root, int to_save, int num, int len)
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

static void	search_pos_more(t_all* all, int *to_do, int *to_save, t_node* root_b)
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
	if (search_min_num(all->root_a, *to_save, root_b->num, all->len_a))
		while (i < all->len_a)
		{
			if (all->root_a->num > root_b->num && *to_save > all->root_a->num)
				break ;
			all->root_a = all->root_a->next;
			(*to_do)++;
            i++;
		}
}


static int  search_pos(t_all* all, t_node* root_b, int num, t_instr *instr)
{
	int to_do;
	int to_save;

	to_do = 0;
	to_save = 0;
	search_pos_more(all, &to_do, &to_save, root_b);
	if (all->root_a->tick == -1)
		to_do = all->len_a - to_do;
	if (num <= to_do + root_b->ind && num != -1)
		return (num);
    else
	{
		instr->instr_a = all->root_a->tick;
		instr->len_a = to_do;
		instr->instr_b = root_b->tick;
		instr->len_b = root_b->ind;
		return (to_do + root_b->ind);
	}
}

void	find_instr(t_all* all, t_instr *instr)
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
		less_tick = search_pos(all, all->root_b, less_tick, instr);
		all->root_b = all->root_b->next;
		all->root_a = first_a;
        i++;
	}
	all->root_b = first_b;
}

int		search_by_index(t_node *root, int num, int len)
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
