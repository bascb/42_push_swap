/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:49:55 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/25 22:58:27 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	clean_exit(t_data *data, int error)
{
	clear_data(data);
	if (error)
		ft_putendl_fd("Error", STDERR_FILENO);
	exit(error);
}

void	free_matrix(void **matrix)
{
	int	i;

	i = 0;
	while (matrix[i] != NULL)
	{
		free(matrix[i]);
		i++;
	}
	free(matrix);
	matrix = NULL;
}

int	check_sorting(t_list **lst)
{
	t_lst	*current;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	while (current->next)
	{
		if (*current->content > *current->next->content)
			return (0);
		current = current->next;
	}
	return (1);
}
