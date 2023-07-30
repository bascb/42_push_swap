/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 19:49:45 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 14:10:32 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	insert_lowest(t_data *data, t_list **moves);

int		get_first_number(t_list **stack);

void	only_rot_a(t_data *data, t_list **moves, int *rot, int nbr)
{
	char	direction;
	int		i;

	if (rot[0] < 0)
	{
		direction = 'i';
		i = -rot[0];
	}
	else
	{
		direction = 'r';
		i = rot[0];
	}
	while (i-- > 0)
	{
		if (direction == 'r')
			insert_move(data, moves, "ra");
		else
			insert_move(data, moves, "rra");
	}
	if (nbr < get_first_number(data->stack_b))
		insert_lowest(data, moves);
	else
		insert_move(data, moves, "pb");
}

void	rotate_both(t_data *data, t_list **moves, int *rot)
{
	int	rr;
	int	r;

	if (rot[0] >= rot[1])
	{
		rr = rot[1];
		r = rot[0] - rot[1];
		while (rr-- > 0)
			insert_move(data, moves, "rr");
		while (r-- > 0)
			insert_move(data, moves, "ra");
	}
	else
	{
		rr = rot[0];
		r = rot[1] - rot[0];
		while (rr-- > 0)
			insert_move(data, moves, "rr");
		while (r-- > 0)
			insert_move(data, moves, "rb");
	}
	insert_move(data, moves, "pb");
}

void	reverse_both(t_data *data, t_list **moves, int *rot)
{
	int	rr;
	int	r;

	if (rot[0] <= rot[1])
	{
		rr = rot[1];
		r = rot[0] - rot[1];
		while (rr++ < 0)
			insert_move(data, moves, "rrr");
		while (r++ < 0)
			insert_move(data, moves, "rra");
	}
	else
	{
		rr = rot[0];
		r = rot[1] - rot[0];
		while (rr++ < 0)
			insert_move(data, moves, "rrr");
		while (r++ < 0)
			insert_move(data, moves, "rrb");
	}
	insert_move(data, moves, "pb");
}

void	reverse_only_a(t_data *data, t_list **moves, int *rot)
{
	int	ra;
	int	rb;

	ra = -rot[0];
	rb = rot[1];
	if (ra > data->size_b - rb)
	{
		while (ra-- > 0)
			insert_move(data, moves, "rrr");
	}
	else
	{
		while (ra-- > 0)
			insert_move(data, moves, "rra");
		while (rb-- > 0)
			insert_move(data, moves, "rb");
	}
	insert_move(data, moves, "pb");
}

void	reverse_only_b(t_data *data, t_list **moves, int *rot)
{
	int	ra;
	int	rb;

	ra = rot[0];
	rb = -rot[1];
	if (rb > data->size_a - ra)
	{
		while (rb-- > 0)
			insert_move(data, moves, "rrr");
	}
	else
	{
		while (ra-- > 0)
			insert_move(data, moves, "ra");
		while (rb-- > 0)
			insert_move(data, moves, "rrb");
	}
	insert_move(data, moves, "pb");
}
