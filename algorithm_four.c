/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm_four.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 21:11:26 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 12:57:29 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sort_four(t_list **a, t_list **b)
{
	int	min;

	min = ft_get_min_value(*a);
	while (ft_atoi((*a)->value) != min)
		ft_rotate_a(*a);
	ft_pb(a, b, 0);
	ft_sort_three(a, b);
	ft_pa(a, b, 0);
}
