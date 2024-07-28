/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_operations.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 12:09:00 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 19:16:01 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rotate(t_list *lst)
{
	t_list	*first;
	t_list	*curr;
	void	*aux;

	first = lst;
	aux = first->value;
	curr = lst;
	while (curr->next)
	{
		curr->value = curr->next->value;
		curr = curr->next;
	}
	curr->value = aux;
}

void	ft_rotate_a(t_list *a)
{
	if (!a || ft_lstsize(a) == 1)
		return ;
	if (ft_lstsize(a) == 2)
		return (ft_swap_a(a));
	ft_rotate(a);
	ft_printf("ra\n");
}

void	ft_rotate_b(t_list *b)
{
	if (!b || ft_lstsize(b) == 1)
		return ;
	if (ft_lstsize(b) == 2)
		return (ft_swap_b(b));
	ft_rotate(b);
	ft_printf("rb\n");
}

void	ft_rr(t_list *a, t_list *b)
{
	ft_rotate_a(a);
	ft_rotate(b);
	ft_printf("rr\n");
}

void	ft_rotate_list(int *top_pos, int *bottom_pos, t_list **b)
{
	if (*top_pos <= *bottom_pos)
	{
		ft_rotate_b(*b);
		(*top_pos)--;
		(*bottom_pos)++;
	}
	else
	{
		ft_reverse_rotate_b(*b);
		(*top_pos)++;
		(*bottom_pos)--;
	}
}
