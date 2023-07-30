/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithms.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:28:32 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 12:00:57 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	put_min_in_start(t_data *data)
{
	t_pos	min;
	int		i;

	min = stack_min(data->stack_a);
	if (data->size_a / 2 >= min.index)
	{
		i = min.index;
		while (i-- > 0)
			rotate_a(data, 0);
	}
	else
	{
		i = data->size_a - min.index;
		while (i-- > 0)
			reverse_a(data, 0);
	}
}

void	select_algorithm(t_data *data)
{
	if (data->size_a == 4 || data->size_a == 5)
		sort_5(data);
	while (data->size_a > 3)
		sort_b(data);
	if (!check_sorting(data->stack_a))
		sort_three(data);
	while (data->size_b)
		sort_a(data);
	put_min_in_start(data);
}
