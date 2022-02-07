/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dequeue_utils2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jbenjy <jbenjy@student.21-school.ru>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/06 22:02:50 by jbenjy            #+#    #+#             */
/*   Updated: 2022/02/07 22:02:06 by jbenjy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static	void	copy_arr(t_node *root, int *arr)
{
	t_node	*begin;
	int		i;

	begin = root;
	i = 0;
	while (root->next != begin)
	{
		arr[i] = root->num;
		root = root->next;
		i++;
	}
	arr[i] = root->num;
}

static	int	*bubble_sort(int *arr, int len)
{
	int	i;
	int	j;
	int	buffer;

	i = 0;
	while (i < len - 1)
	{
		j = i + 1;
		while (j < len)
		{
			if (arr[i] > arr[j])
			{
				buffer = arr[i];
				arr[i] = arr[j];
				arr[j] = buffer;
			}
			j++;
		}
		i++;
	}
	return (arr);
}

int	find_med(t_node *root, int len)
{
	int	*arr;

	if (!root)
		return (-1);
	arr = malloc(sizeof(int) * len);
	if (!arr)
		print_error("Error");
	copy_arr(root, arr);
	arr = bubble_sort(arr, len);
	return (arr[len / 2]);
}
