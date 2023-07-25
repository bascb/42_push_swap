/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:46:17 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/25 22:04:53 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	execute_push(t_data *data, char *move)
{
	if (ft_strncmp(move, "pa", ft_strlen(move)) == 0)
	{
		free(move);
		push_a(data);
	}
	else if (ft_strncmp(move, "pb", ft_strlen(move)) == 0)
	{
		free(move);
		push_b(data);
	}
	else
	{
		free(move);
		clean_exit(data, 1);
	}
}

void	execute_swap(t_data *data, char *move)
{
	if (ft_strncmp(move, "sa", ft_strlen(move)) == 0)
	{
		free(move);
		swap_a(data, 0);
	}
	else if (ft_strncmp(move, "sb", ft_strlen(move)) == 0)
	{
		free(move);
		swap_b(data, 0);
	}
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
	{
		free(move);
		swap_s(data);
	}
	else
	{
		free(move);
		clean_exit(data, 1);
	}
}

void	execute_rotate(t_data *data, char *move)
{
	
}

void	execute_move(t_data *data, char *move)
{
	if (ft_strncmp(move, "pa", ft_strlen(move)) == 0)
		push_a(data);
	else if (ft_strncmp(move, "pb", ft_strlen(move)) == 0)
		push_b(data);
	else if (ft_strncmp(move, "sa", ft_strlen(move)) == 0)
		swap_a(data, 0);
	else if (ft_strncmp(move, "sb", ft_strlen(move)) == 0)
		swap_b(data, 0);
	else if (ft_strncmp(move, "ss", ft_strlen(move)) == 0)
		swap_s(data);
	else if (ft_strncmp(move, "ra", ft_strlen(move)) == 0)
		rotate_a(data, 0);
	else if (ft_strncmp(move, "rb", ft_strlen(move)) == 0)
		rotate_b(data, 0);
	else if (ft_strncmp(move, "rr", ft_strlen(move)) == 0)
		rotate_r(data);
	else if (ft_strncmp(move, "rra", ft_strlen(move)) == 0)
		reverse_a(data, 0);
	else if (ft_strncmp(move, "rrb", ft_strlen(move)) == 0)
		reverse_b(data, 0);
	else if (ft_strncmp(move, "rrr", ft_strlen(move)) == 0)
		reverse_r(data);
	else
		clean_exit(data, 1);
}

void	register_move(t_data *data, char *move)
{
	char	*registered;
	t_list	*new;

	registered = ft_strdup(move);
	if (!registered)
		clean_exit(data, 1);
	new = ft_lstnew(registered);
	if (!new)
	{
		free(registered);
		clean_exit(data, 1);
	}
	ft_lstadd_back(data->history, new);
}
