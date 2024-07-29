/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_five.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/19 17:40:08 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/29 13:44:24 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_move_min_to_front(t_list **a, int min)
{
	int		pos;
	t_list	*temp;

	pos = 0;
	temp = *a;
	while (temp)
	{
		if (ft_atoi(temp->value) == min)
			break ;
		pos++;
		temp = temp->next;
	}
	if (pos < 3)
	{
		while (ft_atoi((*a)->value) != min)
			ft_rotate_a(*a);
	}
	else
	{
		while (ft_atoi((*a)->value) != min)
			ft_reverse_rotate_a(*a);
	}
}

void	ft_sort_five(t_list **a, t_list **b)
{
	int		min;

	min = ft_get_min_value(*a);
	if (ft_atoi(ft_get_last(*a)->value) == min)
		ft_reverse_rotate_a(*a);
	else if (ft_atoi((*a)->value) != min)
	{
		ft_move_min_to_front(a, min);
	}
	ft_pb(a, b, 0);
	ft_sort_four(a, b);
	ft_pa(a, b, 0);
}
