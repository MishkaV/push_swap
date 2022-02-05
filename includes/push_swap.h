/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:56:24 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 11:18:58 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include "stdio.h"
# include <stdlib.h>
# include <unistd.h>
# include <sys/types.h>
# include <sys/uio.h>
# include "constans.h"

typedef struct      s_node
{
    int             num;
    int             index;
    int             gen;
    struct s_node   *next;
    struct s_node   *prev;
}                   t_node;


void    print_error(char *str);

void    print_dequeu(t_node *root);
void    clean_dequeu(t_node *root);


#include "core_operations.h"
#include "operations.h"


t_node  *get_new_node(int num);
t_node  *push_front(t_node *root, t_node *new_node);
t_node  *push_back(t_node *root, t_node *new_node);

#endif