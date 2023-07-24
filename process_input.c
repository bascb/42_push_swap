/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 12:26:04 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/24 21:49:18 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	get_initial_stack(t_data *data, int argc, char **argv)
{
	int		i;
	char	**numbers;

	i = 1;
	while (i < argc)
	{
		numbers = ft_split(argv[i], ' ');
		if (numbers[0] == NULL)
			input_error(data, numbers);
		check_signal(data, numbers);
		check_non_digit(data, numbers);
		check_max_integer(data, numbers);
		insert_number(data, numbers);
		free_matrix((void **) numbers);
		i++;
	}
}

void	insert_number(t_data *data, char **numbers)
{
	int		*value;
	int		i;
	t_list	*new;

	i = 0;
	while (numbers[i] != NULL)
	{
		check_duplicates(data, numbers, i);
		value = ft_calloc(1, sizeof(int));
		if (!value)
			input_error(data, numbers);
		*value = ft_atoi(numbers[i]);
		new = ft_lstnew(value);
		if (!new)
		{
			free(value);
			input_error(data, numbers);
		}
		ft_lstadd_back(data->stack_a, new);
		data->size_a++;
		i++;
	}
}
