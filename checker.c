/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:17:33 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/23 17:56:35 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_data	data;

	(void) argv;
	if (argc < 2)
		exit(0);
	initialize_data(&data);
	get_initial_stack(&data, argc, argv);
	ft_printf("Ready to continue\n");
	clean_exit(&data, 0);
	exit(0);
}
