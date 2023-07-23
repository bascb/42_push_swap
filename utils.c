/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:49:55 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/22 18:58:52 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_data *data, int error)
{
	clear_data(data);
	if (error)
		ft_putendl_fd("Error", 2);
	exit(error);
}
