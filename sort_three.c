/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:56:37 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 01:54:31 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	min_at_top(t_data *data)
{
	reverse_a(data, 0);
	swap_a(data, 0);
}

void	max_at_top(t_data *data, int min_i)
{
	if (min_i == 1)
	{
		rotate_a(data, 0);
	}
	else
	{
		swap_a(data, 0);
		reverse_a(data, 0);
	}
}

void	med_at_top(t_data *data, int min_i)
{
	if (min_i == 1)
	{
		swap_a(data, 0);
	}
	else
	{
		reverse_a(data, 0);
	}
}

void	sort_three(t_data *data)
{
	t_pos	min;
	t_pos	max;

	min = stack_min(data->stack_a);
	max = stack_max(data->stack_a);
	if (min.index == 0)
		min_at_top(data);
	else if (max.index == 0)
		max_at_top(data, min.index);
	else
		med_at_top(data, min.index);
}
