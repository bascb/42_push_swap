/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 21:38:02 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/25 21:38:19 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_a(t_data *data, int simultaneous)
{
	t_list	*first;
	t_list	*last;

	if (data->size_a < 2)
		return ;
	first = *data->stack_a;
	last = ft_lstlast(*data->stack_a);
	*data->stack_a = first->next;
	last->next = first;
	first->next = NULL;
	if (!simultaneous)
		register_move(data, "ra");
}

void	rotate_b(t_data *data, int simultaneous)
{
	t_list	*first;
	t_list	*last;

	if (data->size_b < 2)
		return ;
	first = *data->stack_b;
	last = ft_lstlast(*data->stack_b);
	*data->stack_b = first->next;
	last->next = first;
	first->next = NULL;
	if (!simultaneous)
		register_move(data, "rb");
}

void	rotate_r(t_data *data)
{
	rotate_a(data, 1);
	rotate_b(data, 1);
	register_move(data, "rr");
}
