/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   manage_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 20:46:17 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/26 19:31:14 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	valid_move(char *test, char *move)
{
	size_t	len;

	len = ft_strlen(move);
	if (ft_strlen(test) > len)
		len = ft_strlen(test);
	if (ft_strncmp(move, test, len) == 0)
		return (1);
	return (0);
}

void	execute_move(t_data *data, char *move)
{
	if (valid_move("pa", move))
		push_a(data);
	else if (valid_move("pb", move))
		push_b(data);
	else if (valid_move("sa", move))
		swap_a(data, 0);
	else if (valid_move("sb", move))
		swap_b(data, 0);
	else if (valid_move("ss", move))
		swap_s(data);
	else if (valid_move("ra", move))
		rotate_a(data, 0);
	else if (valid_move("rb", move))
		rotate_b(data, 0);
	else if (valid_move("rr", move))
		rotate_r(data);
	else if (valid_move("rra", move))
		reverse_a(data, 0);
	else if (valid_move("rrb", move))
		reverse_b(data, 0);
	else if (valid_move("rrr", move))
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
