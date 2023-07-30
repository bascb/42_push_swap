/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:11:58 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 01:55:11 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	print_move(void *move)
{
	ft_printf("%s\n", (char *) move);
}

void	print_moves(t_data	*data)
{
	if (!data->history || !*data->history)
		return ;
	ft_lstiter(*data->history, print_move);
}

void	print_stacks(t_data *data, t_list *a, t_list *b)
{
	if (data->stack_a)
		a = *data->stack_a;
	if (data->stack_b)
		b = *data->stack_b;
	ft_printf("%20s%20s\n", "Stack a", "Stack b");
	while (a != NULL || b != NULL)
	{
		if (a != NULL)
		{
			ft_printf("%17d", *(int *) a->content);
			a = a->next;
		}
		else
			ft_printf("%20c", ' ');
		if (b != NULL)
		{
			ft_printf("%20d", *(int *) b->content);
			b = b->next;
		}
		ft_printf("\n");
	}
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argv;
	if (argc < 2)
		exit(0);
	initialize_data(&data);
	get_initial_stack(&data, argc, argv);
	if (check_sorting(data.stack_a))
		clean_exit(&data, 0);
	if (data.size_a == 2)
		swap_a(&data, 0);
	else
		select_algorithm(&data);
	print_moves(&data);
	clean_exit(&data, 0);
	exit(0);
}
