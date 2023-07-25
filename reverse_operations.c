/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_operations.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:20:15 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/25 21:39:58 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	reverse_a(t_data *data, int simultaneous)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	if (data->size_a < 2)
		return ;
	last = ft_lstlast(*data->stack_a);
	new_last = *data->stack_a;
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	first = *data->stack_a;
	*data->stack_a = last;
	last->next = first;
	if (!simultaneous)
		register_move(data, "rra");
}

void	reverse_b(t_data *data, int simultaneous)
{
	t_list	*first;
	t_list	*last;
	t_list	*new_last;

	if (data->size_b < 2)
		return ;
	last = ft_lstlast(*data->stack_b);
	new_last = *data->stack_b;
	while (new_last->next->next)
		new_last = new_last->next;
	new_last->next = NULL;
	first = *data->stack_b;
	*data->stack_b = last;
	last->next = first;
	if (!simultaneous)
		register_move(data, "rrb");
}

void	reverse_r(t_data *data)
{
	reverse_a(data, 1);
	reverse_b(data, 1);
	register_move(data, "rrr");
}
