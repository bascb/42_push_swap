/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/22 18:49:55 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/29 14:34:07 by bcastelo         ###   ########.fr       */
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

t_pos	stack_min(t_list **stack)
{
	t_pos	minimum;
	t_list	*aux;
	int		i;

	if (!stack || !*stack)
	{
		minimum.index = -1;
		return (minimum);
	}
	aux = *stack;
	minimum.value = *(int *)aux->content;
	minimum.index = 0;
	i = 0;
	while (aux != NULL)
	{
		if (*(int *)aux->content < minimum.value)
		{
			minimum.value = *(int *)aux->content;
			minimum.index = i;
		}
		i++;
		aux = aux->next;
	}
	return (minimum);
}

t_pos	stack_max(t_list **stack)
{
	t_pos	maximum;
	t_list	*aux;
	int		i;

	if (!stack || !*stack)
	{
		maximum.index = -1;
		return (maximum);
	}
	aux = *stack;
	maximum.value = *(int *)aux->content;
	maximum.index = 0;
	i = 0;
	while (aux != NULL)
	{
		if (*(int *)aux->content > maximum.value)
		{
			maximum.value = *(int *)aux->content;
			maximum.index = i;
		}
		i++;
		aux = aux->next;
	}
	return (maximum);
}
