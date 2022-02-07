/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:03:57 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 18:57:27 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void init_instr(t_steps* step)
{
	step->count_a = -1;
	step->count_b = -1;
	step->dest_a = 0;
	step->dest_b = 0;
}

static void	ft_steps_markup(t_node *b, int count)
{
	int		i;
	int		iter;
	t_node	*buff;

	i = -1;
	iter = count / 2;
	buff = b;
	while (++i <= iter)
	{
		buff->step = i;
		buff->rotate = 1;
		buff = buff->next;
	}
	if (count % 2 == 0)
		i--;
	while (--i > 0)
	{
		buff->step = i;
		buff->rotate = -1;
		buff = buff->next;
	}
}

static void	ft_instruction_execution(t_all* all, t_steps *steps)
{
	while (steps->count_a > 0)
	{
		if (steps->dest_a == 1)
			all->root_a = ra(all->root_a);
		else
			all->root_a = rra(all->root_a);
		steps->count_a--;
	}
	while (steps->count_b > 0)
	{
		if (steps->dest_b == 1)
			all->root_b = rb(all->root_b);
		else
			all->root_b = rrb(all->root_b);
		steps->count_b--;
	}
	all->root_a = pa(all->root_a, &all->root_b);
	inc_pa(all);
}

static void	sort_extension_more(t_all* all)
{
	t_steps step;

	all->root_a = pa(all->root_a, &all->root_b);
	inc_pa(all);
	while (all->len_b)
	{
		init_instr(&step);
		ft_steps_markup(all->root_a, all->len_a);
		ft_steps_markup(all->root_b, all->len_b);
		ft_minimum_insertion_steps(all, &step);
		ft_instruction_execution(all, &step);
	}
	if ((ft_count_to_min(all->root_a, all->param.min, all->len_a)) > all->len_a / 2)
	{
		while (all->root_a->num != all->param.min)
			all->root_a = rra(all->root_a);
	}
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
	{
		if (all->root_a->num == all->param.min || all->root_a->num == all->param.max)
			all->root_a = ra(all->root_a);
		else
		{
			all->root_b = pb(all->root_b, &all->root_a);
			all->len_a--;
			all->len_b++;
			if (all->param.med < all->root_b->num)
				all->root_b = rb(all->root_b);
		}
	}
	if (all->root_a->next->num > all->root_a->num)
		all->root_a = sa(all->root_a);
	sort_extension_more(all);
}