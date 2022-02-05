/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:25:01 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:40:09 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    t_node *root_a = get_new_node(1);
    t_node *root_b = get_new_node(1);
    

    root_a = push_front(root_a, get_new_node(2));
    root_a = push_front(root_a, get_new_node(3));

    root_b = push_front(root_b, get_new_node(2));
    root_b = push_front(root_b, get_new_node(3));

    print_dequeu(root_a);
    print_dequeu(root_b);


    puts("PUSH");
    root_a = pa(root_a, &root_b);
    print_dequeu(root_a);
    print_dequeu(root_b);
    

    puts("PUSH");
    root_b = pb(root_b, &root_a);
    print_dequeu(root_a);
    print_dequeu(root_b);
    

    clean_dequeu(root_a);
    clean_dequeu(root_b);
    
    // if (argc < 2)
    //     print_error("ERROR!!!");

    return 0;
}