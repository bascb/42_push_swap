/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:00:07 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/23 18:46:03 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <limits.h>

typedef struct s_data
{
	int			total;
	int			max;
	int			min;
	int			size_a;
	int			size_b;
	t_list		**stack_a;
	t_list		**stack_b;
	t_list		**history;
	int			fd;
}				t_data;

void	initialize_data(t_data *data);

void	clear_data(t_data *data);

void	clean_exit(t_data *data, int error);

void	free_matrix(void **matrix);

void	get_initial_stack(t_data *data, int argc, char **argv);

void	insert_number(t_data *data, char **numbers);

void	input_error(t_data *data, char **numbers);

void	check_signal(t_data *data, char **numbers);

void	check_non_digit(t_data *data, char **numbers);

void	check_max_integer(t_data *data, char **numbers);

#endif