/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort3.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 18:44:53 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 18:58:31 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int  ft_smaller_element_detection(t_node *a, int buff, int src, int len_a)
{
	t_node* save;
	int		ret;
    int     i;

	save = a;
	ret = 0;
    i = 0;
	while (i < len_a && ret == 0)
	{
		if (save->num < buff && save->num > src)
			ret = 1;
		save = save->next;
        i++;
	}
	return (ret);
}

static void	ft_help_finding_place(t_all* all, t_node* b, int *action, int *buff)
{
    int i;

    i = 0;
	while (i < all->len_a)
	{
		*buff = all->root_a->num;
		if (b->num > all->root_a->num)
		{
			*action += 1;
			if (b->num < all->root_a->next->num)
				break ;
			all->root_a = all->root_a->next;
            i++;
		}
		else
			break ;
	}
	if (ft_smaller_element_detection(all->root_a, *buff, b->num, all->len_a) == 1)
	{
		while (i < all->len_a)
		{
			if (all->root_a->num < *buff && all->root_a->num > b->num)
				break ;
			*action += 1;
			all->root_a = all->root_a->next;
            i++;
		}
	}
}


static int  ft_finding_place(t_all* all, t_node* b, t_steps *steps, int min)
{
	int action;
	int res;
	int buff;

	action = 0;
	buff = 0;
	ft_help_finding_place(all, b, &action, &buff);
	if (all->root_a->rotate == -1)
		action = all->len_a - action;
	if (min == -1 || (action + b->step) < min)
	{
		steps->dest_a = all->root_a->rotate;
		steps->dest_b = b->rotate;
		steps->count_a = action;
		steps->count_b = b->step;
		res = action + b->step;
	}
	else
		res = min;
	return (res);
}

void	ft_minimum_insertion_steps(t_all* all, t_steps *steps)
{
    int		min_action;
	t_node* first_a;
	t_node* first_b;
    int     i;
    int     len_b;

	min_action = -1;
    i = 0;
    len_b = all->len_b;
	first_a = all->root_a;
	first_b = all->root_b;
	while (i < len_b)
	{
		min_action = ft_finding_place(all, all->root_b, steps, min_action);
		all->root_a = first_a;
		all->root_b = all->root_b->next;
        i++;
	}
	all->root_b = first_b;
}

int		ft_count_to_min(t_node *a, int min, int len_a)
{
	int i;

	i = 0;
	while (i < len_a)
	{
		if (a->num == min)
			break ;
		a = a->next;
		i++;
	}
	return (i);
}
