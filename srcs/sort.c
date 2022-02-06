/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:46:37 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 20:51:15 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_by_three(t_all *all)
{
    if (all->len_a == 2)
    {
        if (all->root_a->num > all->root_a->next->num)
            all->root_a = ra(all->root_a);
    }
    else
    {
        if (all->root_a->num == find_max(all->root_a))
            all->root_a = ra(all->root_a);
        else if (all->root_a->next->num == find_max(all->root_a))
            all->root_a = rra(all->root_a);
        if (all->root_a->num > all->root_a->next->num)
            all->root_a = sa(all->root_a);
    }
}

static void    sort_by_five(t_all *all)
{
    int max;
    int min;

    max = find_max(all->root_a);
    min = find_min(all->root_a);
    while (all->len_b != 2)
    {   
        if (all->root_a->num != min && all->root_a->num != max)
            all->root_a = rra(all->root_a);
        else
        {
            all->root_b = pb(all->root_b, &all->root_a);
            all->len_a--;
            all->len_b++;
        }
    }
    sort_by_three(all);
    while(all->len_b--)
        all->root_a = pa(all->root_a, &all->root_b);
    if (all->root_a->num == min)
        all->root_a = sa(all->root_a);
    all->root_a = ra(all->root_a);
}

void    sort_dequeu(t_all *all)
{
    if (all->len_a == 1)
        return ;
    else if (all->len_a < 4)
        sort_by_three(all);
    else if (all->len_a < 6)
        sort_by_five(all);
    // else
    //     sort_extension(all);
}