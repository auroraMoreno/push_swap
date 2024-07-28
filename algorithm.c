/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/20 11:20:19 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 23:28:19 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_chunk_has_elements(t_list *a, int i, int *chunks)
{
	t_list	*curr;

	curr = a;
	while (curr)
	{
		if (ft_is_in_range(ft_atoi(curr->value), i, chunks))
			return (1);
		curr = curr->next;
	}
	return (0);
}

void	ft_pb_and_update(t_list **a, t_list **b, t_list **prev, t_list **curr)
{
	t_list	*next;

	next = (*curr)->next;
	ft_pb(a, b, 0);
	if (*prev)
		(*prev)->next = next;
	else
		*a = next;
	*curr = next;
}

void	ft_initial_iteration(t_list **a, t_list **b, int *chunks)
{
	t_list	*curr;
	t_list	*prev;
	int		i;

	prev = NULL;
	curr = *a;
	i = 0;
	while (curr)
	{
		if (ft_is_in_range(ft_atoi(curr->value), i, chunks))
			ft_pb_and_update(a, b, &prev, &curr);
		else
		{
			prev = curr;
			curr = curr->next;
		}
		i++;
	}
}

int	ft_move_to_b(t_list **a, t_list **b, int *chunks)
{
	int	i;

	ft_initial_iteration(a, b, chunks);
	i = 0;
	while (*a)
	{
		while (ft_chunk_has_elements(*a, i, chunks))
		{
			if (ft_is_in_range(ft_atoi((*a)->value), i, chunks) && (*a)->next
				&& ft_is_in_range(ft_atoi((*a)->next->value), i, chunks))
			{
				ft_pb(a, b, 0);
				ft_pb(a, b, 1);
			}
			else if (ft_is_in_range(ft_atoi((*a)->value), i, chunks))
				ft_pb(a, b, 0);
			else if ((*a)->next
				&& ft_is_in_range(ft_atoi((*a)->next->value), i, chunks))
				ft_pb(a, b, 1);
			else
				ft_rotate_a(*a);
		}
		i++;
	}
	return (i);
}

void	ft_move_to_a(t_list **a, t_list **b)
{
	int	pos_max;
	int	top_pos;
	int	bottom_pos;

	while (*b)
	{
		while (ft_get_max_pos(*b))
		{
			pos_max = ft_get_max_pos(*b);
			top_pos = pos_max;
			bottom_pos = ft_lstsize(*b) - pos_max;
			ft_rotate_list(&top_pos, &bottom_pos, b);
		}
		ft_pa(a, b, 0);
	}
}
