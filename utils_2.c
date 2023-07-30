/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 09:50:52 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 10:33:55 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	check_reverse_sorting(t_list **lst)
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
		if (*current_value < *next_value)
			return (0);
		current = current->next;
	}
	return (1);
}
