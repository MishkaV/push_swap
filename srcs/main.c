/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:25:01 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 20:56:37 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    t_all all;
    
    init_all(&all);
    if (argc < 2)
        exit(1);
    is_valid_argv(argc, argv);
    parser(&all, argc, argv);
    if (!is_sorted_ascending(all.root_a))
        sort_dequeu(&all);
    clean_dequeu(all.root_a);
    clean_dequeu(all.root_b);
    return (0);
}