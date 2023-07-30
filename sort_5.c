/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 08:25:05 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 09:09:36 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_stack_moves(t_data *data, int i)
{
	if (data->size_a / 2 >= i)
		return (i);
	return (i - data->size_a);
}

void	sort_5(t_data *data)
{
	t_pos	min;
	int		i;

	while (data->size_a > 3)
	{
		min = stack_min(data->stack_a);
		i = check_stack_moves(data, min.index);
		if (i < 0)
		{
			while (i++ < 0)
				reverse_a(data, 0);
		}
		else
		{
			while (i-- > 0)
				rotate_a(data, 0);
		}
		push_b(data);
	}
}
