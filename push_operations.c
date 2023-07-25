/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:58:08 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/25 21:26:32 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_a(t_data *data)
{
	t_list	*pushed;

	if (!data->size_b)
		return ;
	pushed = *data->stack_b;
	*data->stack_b = pushed->next;
	ft_lstadd_front(data->stack_a, pushed);
	data->size_b--;
	data->size_a++;
	register_move(data, "pa");
}

void	push_b(t_data *data)
{
	t_list	*pushed;

	if (!data->size_a)
		return ;
	pushed = *data->stack_a;
	*data->stack_a = pushed->next;
	ft_lstadd_front(data->stack_b, pushed);
	data->size_a--;
	data->size_b++;
	register_move(data, "pb");
}
