/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:29:17 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 21:15:44 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void clean_dic(char** dic)
{
	int i;

	if (!dic)
		return ;
		
	i = 0;
	while (dic[i])
	{
		free(dic[i]);
		i++;
	}
	free(dic);
}

void    parser(t_all* all, int argc, char** argv)
{
	int		i;
	int		j;
	t_node*	node;
	char**	dic;
	
	i = 0;
	while (++i < argc)
	{
		dic = ft_split(argv[i], ' ');
		j = 0;
		while (dic[j])
		{
			node = get_new_node(ft_atoi(dic[j]));
			all->root_a = push_front(all->root_a, node);
			j++;
		}

		clean_dic(dic);
	}
}