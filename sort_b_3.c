/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 10:42:57 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 12:15:14 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_moves_list(t_list	**moves)
{
	ft_lstclear(moves, free);
	free(moves);
}

t_list	**update_best(t_list **old, t_list **new)
{
	free_moves_list(old);
	return (new);
}

void	insert_lowest(t_data *data, t_list **moves)
{
	t_pos	max;
	int		i;

	if (!check_reverse_sorting(data->stack_b))
	{
		max = stack_max(data->stack_b);
		if (data->size_b / 2 >= max.index)
		{
			i = max.index;
			while (i-- > 0)
				insert_move(data, moves, "rb");
		}
		else
		{
			i = data->size_b - max.index;
			while (i-- > 0)
				insert_move(data, moves, "rrb");
		}
	}
	insert_move(data, moves, "pb");
	insert_move(data, moves, "rb");
}

int	get_first_number(t_list **stack)
{
	t_list	*list;
	int		nbr;

	if (!stack || !*stack)
		return (0);
	list = *stack;
	nbr = *(int *)list->content;
	return (nbr);
}
