/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 17:25:01 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/02 21:25:18 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int main(int argc, char **argv)
{
    (void)argc;
    (void)argv;

    t_node *root = get_new_node(1);
    print_dequeu(root);

    root = push_front(root, get_new_node(2));
    print_dequeu(root);

    root = push_back(root, get_new_node(3));
    print_dequeu(root);
    
    clean_dequeu(root);
    // if (argc < 2)
    //     print_error("ERROR!!!");

    return 0;
}