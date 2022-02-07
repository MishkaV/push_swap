/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 20:29:17 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 22:07:11 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	clean_dic(char	**dic)
{
	int	i;

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

static	void	check_duplicates(t_node	*root)
{
	t_node	*i;
	t_node	*j;
	t_node	*i_begin;
	t_node	*j_begin;

	if (!root)
		exit(1);
	i = root;
	i_begin = i;
	j = root->next;
	while (i->next != i_begin)
	{
		j_begin = j;
		while (j->next != j_begin)
		{
			if (i->num == j->num)
				print_error("Error");
			j = j->next;
		}
		i = i->next;
		j = j_begin->next;
		j_begin = j;
	}
}

void	parser(t_all *all, int argc, char **argv)
{
	int		i;
	int		j;
	t_node	*node;
	char	**dic;

	i = 0;
	while (++i < argc)
	{
		dic = ft_split(argv[i], ' ');
		j = 0;
		while (dic[j])
		{
			node = get_new_node(ft_atoi(dic[j]));
			if (!node)
			{
				clean_dequeu(all->root_a);
				print_error("Error");
			}
			all->root_a = push_back(all->root_a, node);
			all->len_a++;
			j++;
		}
		clean_dic(dic);
	}
	check_duplicates(all->root_a);
}
