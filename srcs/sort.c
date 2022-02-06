/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 18:46:37 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 19:41:56 by jbenjy           ###   ########.fr       */
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
    (void)all;
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