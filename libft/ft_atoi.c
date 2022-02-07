/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/05 15:13:42 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 21:51:02 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	print_error(void)
{
	ft_putstr_fd("Error", 0);
	ft_putstr_fd("\n", 0);
	exit(1);
}

static void	check_maxs(long num)
{
	long	int_max;
	long	int_min;

	int_max = 2147483647;
	int_min = -2147483648;
	if (num > int_max || num < int_min)
		print_error();
}

static int	check(char c)
{
	if (c == '\t')
		return (0);
	if (c == '\v')
		return (0);
	if (c == '\f')
		return (0);
	if (c == '\r')
		return (0);
	if (c == '\n')
		return (0);
	if (c == ' ')
		return (0);
	return (1);
}

int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (!check(*str) && *str)
		str++;
	if (*str == '-' && str[1] >= '0' && str[1] <= '9')
	{
		sign = -sign;
		str++;
	}
	if (*str == '+' && str[1] >= '0' && str[1] <= '9')
		str++;
	while (*str != '\0' && *str >= '0' && *str <= '9')
		num = num * 10 + *str++ - '0';
	check_maxs(num * sign);
	return (num * sign);
}
