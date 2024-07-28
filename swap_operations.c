/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/30 10:42:10 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 19:23:27 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list *a)
{
	t_list	*first;
	t_list	*second;
	void	*aux;

	if (ft_lstsize(a) <= 1)
		return ;
	first = a;
	second = a->next;
	aux = first->value;
	first->value = second->value;
	second->value = aux;
	ft_printf("sa\n");
}

void	ft_swap_b(t_list *b)
{
	t_list	*first;
	t_list	*second;
	void	*aux;

	if (ft_lstsize(b) <= 1)
		return ;
	first = b;
	second = b->next;
	aux = first->value;
	first->value = second->value;
	second->value = aux;
	ft_printf("sb\n");
}

void	ft_ss(t_list *a, t_list *b)
{
	ft_swap_a(a);
	ft_swap_b(b);
	ft_printf("ss\n");
}
