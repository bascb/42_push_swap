/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_b.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bcastelo <bcastelo@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 10:53:33 by bcastelo          #+#    #+#             */
/*   Updated: 2023/07/30 14:13:34 by bcastelo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	only_rot_a(t_data *data, t_list **moves, int *rot, int nbr);

void	rotate_both(t_data *data, t_list **moves, int *rot);

void	reverse_both(t_data *data, t_list **moves, int *rot);

void	reverse_only_a(t_data *data, t_list **moves, int *rot);

void	reverse_only_b(t_data *data, t_list **moves, int *rot);

void	free_moves_list(t_list	**moves);

t_list	**update_best(t_list **old, t_list **new);

int	evaluate_stack_a_moves(t_data *data, int i)
{
	if (data->size_a / 2 >= i)
		return (i);
	return (i - data->size_a);
}

int	evaluate_stack_b_moves(t_data *data, int nbr)
{
	t_list	*current;
	int		j;
	int		k;
	int		next_lower;
	int		cur_nbr;

	current = *data->stack_b;
	j = 0;
	k = 0;
	next_lower = INT_MIN;
	while (current != NULL)
	{
		cur_nbr = *(int *)current->content;
		if (cur_nbr < nbr && cur_nbr > next_lower)
		{
			next_lower = cur_nbr;
			k = j;
		}
		j++;
		current = current->next;
	}
	if (data->size_b / 2 >= k)
		return (k);
	return (k - data->size_b);
}

void	combine_moves(t_data *data, t_list **moves, int *rot, int nbr)
{
	if (rot[1] == 0)
		only_rot_a(data, moves, rot, nbr);
	else if (rot[0] >= 0 && rot[1] >= 0)
		rotate_both(data, moves, rot);
	else if (rot[0] < 0 && rot[1] < 0)
		reverse_both(data, moves, rot);
	else if (rot[0] < 0 && rot[1] >= 0)
		reverse_only_a(data, moves, rot);
	else if (rot[0] >= 0 && rot[1] < 0)
		reverse_only_b(data, moves, rot);
}

t_list	**evaluate_nbr_moves(t_data *data, int i, int nbr)
{
	t_list	**best;
	int		rot[2];

	best = ft_calloc(1, sizeof(t_list *));
	if (!best)
		clean_exit(data, 1);
	if (data->size_b > 0)
	{
		rot[0] = evaluate_stack_a_moves(data, i);
		rot[1] = evaluate_stack_b_moves(data, nbr);
		combine_moves(data, best, rot, nbr);
	}
	else
		insert_move(data, best, "pb");
	return (best);
}

void	sort_b(t_data *data)
{
	t_list	**best;
	t_list	**nbr_moves;
	t_list	*current;
	int		i;
	int		nbr;

	current = *data->stack_a;
	i = 0;
	while (current != NULL)
	{
		nbr = *(int *)current->content;
		nbr_moves = evaluate_nbr_moves(data, i, nbr);
		if (i == 0)
			best = nbr_moves;
		else if (ft_lstsize(*nbr_moves) < ft_lstsize(*best))
			best = update_best(best, nbr_moves);
		else
			free_moves_list(nbr_moves);
		i++;
		current = current->next;
	}
	execute_moves(data, best);
	free_moves_list(best);
}
