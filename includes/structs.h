/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/07 21:46:38 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 21:47:09 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H

typedef struct s_node
{
	int				num;
	int				ind;
	int				tick;
	struct s_node	*next;
	struct s_node	*prev;
}	t_node;

typedef struct s_param
{
	int	min;
	int	max;
	int	med;
}	t_param;

typedef struct s_all
{
	t_node	*root_a;
	t_node	*root_b;
	t_param	param;
	int		len_a;
	int		len_b;
}	t_all;

typedef struct s_instr
{
	int	len_a;
	int	len_b;
	int	instr_a;
	int	instr_b;
}	t_instr;

#endif