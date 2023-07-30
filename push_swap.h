/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:00:07 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 09:53:23 by bcastelo         ###   ########.fr       */
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
	char		*move;
	t_list		**stack_a;
	t_list		**stack_b;
	t_list		**history;
	int			fd;
}				t_data;

typedef struct s_pos
{
	int			value;
	int			index;
}				t_pos;

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

void	check_duplicates(t_data *data, char **numbers, int i);

int		check_sorting(t_list **lst);

int		check_reverse_sorting(t_list **lst);

t_pos	stack_min(t_list **stack);

t_pos	stack_max(t_list **stack);

void	execute_move(t_data *data, char *move);

void	execute_moves(t_data *data, t_list **moves);

void	insert_move(t_data *data, t_list **moves_lst, char *move);

void	register_move(t_data *data, char *move);

void	push_a(t_data *data);

void	push_b(t_data *data);

void	swap_a(t_data *data, int simultaneous);

void	swap_b(t_data *data, int simultaneous);

void	swap_s(t_data *data);

void	rotate_a(t_data *data, int simultaneous);

void	rotate_b(t_data *data, int simultaneous);

void	rotate_r(t_data *data);

void	reverse_a(t_data *data, int simultaneous);

void	reverse_b(t_data *data, int simultaneous);

void	reverse_r(t_data *data);

void	select_algorithm(t_data *data);

void	sort_three(t_data *data);

void	sort_5(t_data *data);

void	sort_b(t_data *data);

void	sort_a(t_data *data);

void	print_stacks(t_data *data, t_list *a, t_list *b);

#endif