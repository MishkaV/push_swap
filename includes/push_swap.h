/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 19:56:24 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/06 19:57:29 by jbenjy           ###   ########.fr       */
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

typedef struct	s_all
{
	t_node*		root_a;
	t_node*		root_b;
	int			len_a;
	int			len_b;
}				t_all;

void    print_error(char *str);
void	init_all(t_all* all);

void    print_dequeue(t_node *root);
void    clean_dequeu(t_node *root);
int 	is_sorted_ascending(t_node* root);
int		find_max(t_node* root);
int		find_min(t_node* root);

#include "core_operations.h"
#include "operations.h"

t_node  *get_new_node(int num);
t_node  *push_front(t_node *root, t_node *new_node);
t_node  *push_back(t_node *root, t_node *new_node);

void	is_valid_argv(int argc, char **argv);
void    parser(t_all* all, int argc, char** argv);

void    sort_dequeu(t_all *all);

#endif