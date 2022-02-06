/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 21:03:57 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 22:29:55 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void    sort_extension_more(t_all* all)
{
    all->root_a = pa(all->root_a, &all->root_b);
    
}

void    sort_extension(t_all* all)
{
    int max;
    int min;
    int med;
    
    max = find_max(all->root_a);
    min = find_min(all->root_a);
    med = find_med(all->root_a, all->len_a);
    while (all->len_a != 2)
    {
        if (all->root_a->num == min || all->root_a->num == max)
            all->root_a = ra(all->root_a);
        else
        {
            all->root_b = pb(all->root_b, &all->root_a);
            all->len_a--;
            all->len_b++;
            if (med < all->root_b->num)
                all->root_b = rb(all->root_b);
        }
    }
    if (all->root_a->next->num > all->root_a->num)
        all->root_a = sa(all->root_a);
    sort_extension_more(all);
}