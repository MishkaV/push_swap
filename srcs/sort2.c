/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:03:57 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 21:19:58 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_instr(t_instr* instr)
{
	instr->len_a = -1;
	instr->instr_a = 0;
	instr->len_b = -1;
	instr->instr_b = 0;
}

static void	tick_nodes(t_node *root_b, int len)
{
	int		i;
	
	i = 0;
	while (i <= len / 2)
	{
		root_b->tick = 1;
		root_b->ind = i;
		root_b = root_b->next;
		i++;
	}
	if (!(len % 2))
		i--;
	while (--i)
	{
		root_b->tick = -1;
		root_b->ind = i;
		root_b = root_b->next;
	}
}

static void	make_instr(t_all* all, t_instr *instr)
{
	while (instr->len_b)
	{
		if (instr->instr_b != 1)
			all->root_b = rrb(all->root_b);
		else
			all->root_b = rb(all->root_b);
		instr->len_b--;
	}
	while (instr->len_a)
	{
		if (instr->instr_a != 1)
			all->root_a = rra(all->root_a);
		else
			all->root_a = ra(all->root_a);
		instr->len_a--;
	}
	all->root_a = pa(all->root_a, &all->root_b);
	inc_pa(all);
}

static void	sort_extension_more(t_all* all)
{
	t_instr instr;
	all->root_a = pa(all->root_a, &all->root_b);
	inc_pa(all);
	while (all->len_b)
	{
		init_instr(&instr);
		tick_nodes(all->root_a, all->len_a);
		tick_nodes(all->root_b, all->len_b);
		find_instr(all, &instr);
		make_instr(all, &instr);
	}
	if ((all->len_a / 2 < search_by_index(all->root_a, all->param.min, all->len_a)))
		while (all->root_a->num != all->param.min)
			all->root_a = rra(all->root_a);
	else
		while (all->root_a->num != all->param.min)
			all->root_a = ra(all->root_a);
}

void    sort_extension(t_all* all)
{	
	all->param.max = find_max(all->root_a);
	all->param.min = find_min(all->root_a);
	all->param.med = find_med(all->root_a, all->len_a);
	while (all->len_a != 2)
		if (all->root_a->num != all->param.min && all->root_a->num != all->param.max)
		{
			all->root_b = pb(all->root_b, &all->root_a);
			inc_pb(all);
			if (all->param.med < all->root_b->num)
				all->root_b = rb(all->root_b);
		}
		else
			all->root_a = ra(all->root_a);
	if (all->root_a->next->num > all->root_a->num)
		all->root_a = sa(all->root_a);
	sort_extension_more(all);
}