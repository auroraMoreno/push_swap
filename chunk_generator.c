/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_generator.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/28 23:24:56 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 23:25:26 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_generate_segments(t_list *lst)
{
	int	*segments;
	int	min;
	int	number_segments;
	int	interval_size;
	int	i;

	min = ft_get_min_value(lst);
	if (ft_lstsize(lst) <= 10)
		number_segments = 2;
	else if (ft_lstsize(lst) <= 100)
		number_segments = 7;
	else
		number_segments = 10;
	interval_size = (ft_get_max_value(lst) - min) / number_segments;
	segments = (int *)malloc((number_segments + 1) * sizeof(int));
	if (!segments)
		return (NULL);
	i = 0;
	while (i < number_segments)
	{
		segments[i] = min + (i * interval_size);
		i++;
	}
	segments[i] = ft_get_max_value(lst) + 1;
	return (segments);
}
