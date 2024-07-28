/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_operations.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 20:36:38 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 18:19:56 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_insert_first(t_list **lst, t_list *new_value)
{
	t_list	*curr;

	if (*lst)
	{
		curr = *lst;
		*lst = new_value;
		new_value->next = curr;
	}
	else
		*lst = new_value;
}

void	ft_push(t_list **dest, t_list **src, int insert_next)
{
	t_list	*head;
	t_list	*new_first;
	t_list	*next;

	if (insert_next == 1 && (*src)->next)
	{
		next = (*src)->next;
		new_first = ft_lstnew(next->value);
		(*src)->next = next->next;
		ft_lst_del_elment(next, NULL);
	}
	else
	{
		head = (*src)->next;
		new_first = ft_lstnew((*src)->value);
		ft_lst_del_elment(*src, NULL);
		*src = head;
	}
	ft_insert_first(dest, new_first);
}

void	ft_pa(t_list **a, t_list **b, int insert_next)
{
	if (!*b)
		return ;
	ft_push(a, b, insert_next);
	ft_printf("pa\n");
}

void	ft_pb(t_list **a, t_list **b, int insert_next)
{
	if (!*a)
		return ;
	ft_push(b, a, insert_next);
	ft_printf("pb\n");
}
