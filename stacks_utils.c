/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/16 11:28:08 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 20:49:05 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstsize(t_list *lst)
{
	t_list	*curr;
	int		len;

	curr = lst;
	len = 0;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	return (len);
}

t_list	*ft_lstnew(void *content)
{
	t_list	*element;

	element = (t_list *)malloc(sizeof(t_list));
	if (!element)
		return (NULL);
	element->value = content;
	element->next = NULL;
	return (element);
}

t_list	*ft_insert_initial(char *args[], int index)
{
	t_list	*numbers;

	if (!args[index])
		return (NULL);
	numbers = ft_lstnew((char *) args[index]);
	numbers->next = ft_insert_initial(args, ++index);
	return (numbers);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*temp;

	if (!*lst)
		return ;
	while (*lst)
	{
		temp = (*lst)->next;
		if (del)
			del((*lst)->value);
		free(*lst);
		*lst = temp;
	}
	*lst = NULL;
}

void	ft_lst_del_elment(t_list *el, void (*del)(void *))
{
	if (!el)
		return ;
	if (del)
		del(el->value);
	free(el);
}
