/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/24 22:45:10 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/24 22:57:09 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_a(t_data *data)
{
	t_list	*first;
	t_list	*second;
	void	*aux;

	if (data->size_a < 2)
		return ;
	first = *data->stack_a;
	second = first->next;
	aux = first->content;
	first->content = second->content;
	second->content = aux;
}

void	swap_b(t_data *data)
{
	t_list	*first;
	t_list	*second;
	void	*aux;

	if (data->size_b < 2)
		return ;
	first = *data->stack_b;
	second = first->next;
	aux = first->content;
	first->content = second->content;
	second->content = aux;
}

void	swap_s(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
