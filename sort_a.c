/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_a.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:44:52 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 09:09:31 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	evaluate_a_moves(t_data *data, int nbr)
{
	t_list	*current;
	int		j;
	int		k;
	int		next_up;
	int		cur_nbr;

	current = *data->stack_a;
	j = 0;
	k = 0;
	next_up = INT_MAX;
	while (current != NULL)
	{
		cur_nbr = *(int *)current->content;
		if (cur_nbr > nbr && cur_nbr < next_up)
		{
			next_up = cur_nbr;
			k = j;
		}
		j++;
		current = current->next;
	}
	return (k);
}

void	bigger_nbr(t_data *data)
{
	while (!check_sorting(data->stack_a))
		reverse_a(data, 0);
	push_a(data);
	rotate_a(data, 0);
}

void	sort_a(t_data *data)
{
	t_list	*a;
	t_list	*b;
	int		nbr_a;
	int		nbr_b;
	int		i;

	a = *data->stack_a;
	nbr_a = *(int *)a->content;
	b = *data->stack_b;
	nbr_b = *(int *)b->content;
	i = evaluate_a_moves(data, nbr_b);
	if (i == 0 && nbr_a < nbr_b)
	{
		bigger_nbr(data);
		return ;
	}
	while (i-- > 0)
		rotate_a(data, 0);
	push_a(data);
}
