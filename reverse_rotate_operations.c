/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_operations.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 01:50:36 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 19:12:28 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_get_last(t_list *lst)
{
	t_list	*last;

	last = lst;
	if (!last)
		return (0);
	while (last->next)
		last = last->next;
	return (last);
}

void	ft_reserve_rotate(t_list *lst)
{
	t_list	*last;
	t_list	*curr;
	void	*aux_last;
	void	*aux_first;
	void	*next;

	last = ft_get_last(lst);
	aux_last = last->value;
	aux_first = lst->value;
	curr = lst->next;
	while (curr->next)
	{
		next = curr->value;
		curr->value = aux_first;
		aux_first = next;
		curr = curr->next;
	}
	curr->value = aux_first;
	lst->value = aux_last;
}

void	ft_reverse_rotate_a(t_list *a)
{
	if (!a || ft_lstsize(a) == 1)
		return ;
	if (ft_lstsize(a) == 2)
		return (ft_swap_a(a));
	ft_reserve_rotate(a);
	ft_printf("rra\n");
}

void	ft_reverse_rotate_b(t_list *b)
{
	if (!b || ft_lstsize(b) == 1)
		return ;
	if (ft_lstsize(b) == 2)
		return (ft_swap_b(b));
	ft_reserve_rotate(b);
	ft_printf("rrb\n");
}

void	ft_rrr(t_list *a, t_list *b)
{
	ft_reverse_rotate_a(a);
	ft_reserve_rotate(b);
	ft_printf("rrr\n");
}
