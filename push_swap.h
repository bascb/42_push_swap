/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 10:00:07 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/22 18:59:09 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "libft.h"
# include <stdio.h>
# include <fcntl.h>

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

#endif