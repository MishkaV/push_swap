/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/05 13:09:20 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/05 13:48:50 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	is_spaces(char *str)
{
	while(*str)
	{
		if (!(*str == '\n' || *str == '\t' || *str == ' ' || *str == '\r' || *str == '\v'))
			return (1);
		str++;
	}
	return (0);
}

static void is_valid_str(char *str)
{
	int	i;
	int	have_number;
	int	have_sign;

	i = 0;
	have_number = 0;
	have_sign = 0;
	while (i < (int)ft_strlen(str))
	{
		if (ft_isdigit(str[i]))
			have_number = 1;
		else if (str[i] == '\t' || str[i] == ' ')
		{
			if (have_sign && !have_number)
				print_error("Error");
			have_number = 0;
			have_sign = 0;
		}
		else if (str[i] == '-' || str[i] == '+')
		{
			if (have_sign || have_number || !str[i + 1])
				print_error("Error");
			have_sign = 1;
		}
		else
			print_error("Error");
		i++;
	}
}

void	is_valid_argv(int argc, char **argv)
{
	int i;

	i = 0;
	while (++i < argc)
		if(!is_spaces(argv[i]))
			is_valid_str(argv[i]);
}