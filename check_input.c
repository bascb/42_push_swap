/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/23 18:17:50 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/24 21:11:35 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	input_error(t_data *data, char **numbers)
{
	free_matrix((void **) numbers);
	clean_exit(data, 1);
}

void	check_signal(t_data *data, char **numbers)
{
	int	i;

	i = 0;
	while (numbers[i] != NULL)
	{
		if (ft_strlen(numbers[i]) == 1
			&& !ft_charinset(numbers[i][0], "0123456789"))
			input_error(data, numbers);
		if (!ft_charinset(numbers[i][0], "-+0123456789"))
			input_error(data, numbers);
		i++;
	}
}

void	check_non_digit(t_data *data, char **numbers)
{
	int	i;
	int	j;

	i = 0;
	while (numbers[i] != NULL)
	{
		j = 0;
		if (numbers[i][j] == '-' || numbers[i][j] == '+')
			j++;
		while (numbers[i][j])
		{
			if (!ft_charinset(numbers[i][j], "0123456789"))
				input_error(data, numbers);
			j++;
		}
		i++;
	}
}

void	check_max_integer(t_data *data, char **numbers)
{
	int		i;
	char	*start;

	i = 0;
	while (numbers[i] != NULL)
	{
		start = numbers[i];
		if (numbers[i][0] == '-' || numbers[i][0] == '+')
			start++;
		while (*start == '0')
			start++;
		if (ft_strlen(start) < 10)
			return ;
		if (numbers[i][0] == '-')
		{
			if (ft_strncmp(start, "2147483648", ft_strlen(start)) > 0)
				input_error(data, numbers);
		}
		else if (ft_strncmp(start, "2147483647", ft_strlen(start)) > 0)
			input_error(data, numbers);
		i++;
	}
}

void	check_duplicates(t_data *data, char **numbers, int i)
{
	t_list	*next;

	next = *data->stack_a;
	while (next != NULL)
	{
		if (*(int *)next->content == ft_atoi(numbers[i]))
			input_error(data, numbers);
		next = next->next;
	}
}
