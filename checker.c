/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:17:33 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/26 19:43:40 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	remove_newline_char(t_data *data, char *str)
{
	char	*c;

	c = ft_strchr(str, '\n');
	if (c == NULL)
		clean_exit(data, 1);
	*c = '\0';
}

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argv;
	if (argc < 2)
		exit(0);
	initialize_data(&data);
	get_initial_stack(&data, argc, argv);
	data.move = get_next_line(STDIN_FILENO);
	while (data.move != NULL)
	{
		remove_newline_char(&data, data.move);
		execute_move(&data, data.move);
		free(data.move);
		data.move = get_next_line(STDIN_FILENO);
	}
	if (check_sorting(data.stack_a) && !data.size_b)
		ft_printf("OK\n");
	else
		ft_printf("KO\n");
	clean_exit(&data, 0);
	exit(0);
}
