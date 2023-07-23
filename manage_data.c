/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 16:12:41 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/22 21:05:28 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clear_list(t_list **lst)
{
	ft_lstclear(lst, free);
	free(lst);
	lst = NULL;
}

void	initialize_data(t_data *data)
{
	data->total = 0;
	data->max = 0;
	data->min = 0;
	data->size_a = 0;
	data->size_b = 0;
	data->stack_a = ft_calloc(1, sizeof(t_data *));
	data->stack_b = ft_calloc(1, sizeof(t_data *));
	data->history = ft_calloc(1, sizeof(t_data *));
	data->fd = -1;
}

void	clear_data(t_data *data)
{
	if (data->fd != -1)
	{
		close(data->fd);
		data->fd = -1;
	}
	if (data->stack_a != NULL)
	{
		clear_list(data->stack_a);
		data->stack_a = NULL;
	}
	if (data->stack_b != NULL)
	{
		clear_list(data->stack_b);
		data->stack_b = NULL;
	}
	if (data->history != NULL)
	{
		clear_list(data->history);
		data->history = NULL;
	}
}
