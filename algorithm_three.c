/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_three.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:11:11 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 13:13:05 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_first_case(t_list **a, t_list **b)
{
	(void)b;
	ft_swap_a(*a);
	if (ft_issorted(*a))
		return ;
	ft_swap_a(*a);
	ft_rotate_a(*a);
}

void	ft_second_case(t_list **a, t_list **b)
{
	(void)b;
	ft_reverse_rotate_a(*a);
	if (!ft_issorted(*a))
		ft_swap_a(*a);
}

void	ft_third_case(t_list **a, t_list **b)
{
	(void)b;
	ft_rotate_a(*a);
	ft_swap_a(*a);
}

void	ft_sort_three(t_list **a, t_list **b)
{
	char	*first;
	char	*second;
	char	*third;

	if (ft_issorted(*a))
		return ;
	first = (*a)->value;
	second = (*a)->next->value;
	third = (*a)->next->next->value;
	if ((ft_atoi(first) > ft_atoi(second))
		&& (ft_atoi(second) < ft_atoi(third)))
	{
		ft_first_case(a, b);
		return ;
	}
	if ((ft_atoi(first) < ft_atoi(second))
		&& (ft_atoi(second) > ft_atoi(third)))
	{
		ft_second_case(a, b);
		return ;
	}
	ft_third_case(a, b);
	return ;
}
