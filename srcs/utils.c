/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/02 20:10:10 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/02 20:16:27 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void    print_error(char *str)
{
    ft_putstr_fd(str, STANDART_OUTPUT);
    ft_putstr_fd("\n", STANDART_OUTPUT);
    exit(EXIT_ERROR);
}