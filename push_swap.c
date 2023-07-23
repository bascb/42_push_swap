/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:11:58 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/22 18:58:31 by bcastelo         ###   ########.fr       */
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
	ft_printf("Ready to continue\n");
	clean_exit(&data, 0);
	exit(0);
}
