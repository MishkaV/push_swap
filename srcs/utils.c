/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:10:10 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 22:15:22 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_error(char *str)
{
	ft_putstr_fd(str, STANDART_OUTPUT);
	ft_putstr_fd("\n", STANDART_OUTPUT);
	exit(EXIT_ERROR);
}

void	init_all(t_all *all)
{
	all->root_a = 0;
	all->root_b = 0;
	all->len_a = 0;
	all->len_b = 0;
}

void	inc_pa(t_all *all)
{
	all->len_a++;
	all->len_b--;
}

void	inc_pb(t_all *all)
{
	all->len_b++;
	all->len_a--;
}
