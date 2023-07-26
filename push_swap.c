/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:11:58 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/26 22:08:51 by bcastelo         ###   ########.fr       */
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
	print_moves(&data);
	clean_exit(&data, 0);
	exit(0);
}
