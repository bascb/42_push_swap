/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:49:55 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/26 18:44:12 by bcastelo         ###   ########.fr       */
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
	t_list	*current;
	int		*current_value;
	int		*next_value;

	if (!lst || !*lst)
		return (0);
	current = *lst;
	while (current->next)
	{
		current_value = (int *) current->content;
		next_value = (int *) current->next->content;
		if (*current_value > *next_value)
			return (0);
		current = current->next;
	}
	return (1);
}
