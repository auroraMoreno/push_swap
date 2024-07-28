/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/17 16:51:51 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 13:52:58 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_error_checking(t_list *lst)
{
	if (ft_lstsize(lst) == 1)
	{
		ft_error_handling(lst);
		exit(EXIT_SUCCESS);
	}
	ft_error_handling(lst);
}

void	ft_error_handling(t_list *lst)
{
	t_list	*curr;

	if (ft_check_duplicates(lst) == 1)
		ft_error();
	curr = lst;
	while (curr)
	{
		if (!ft_isint(curr->value) || ft_strlen(curr->value) < 1)
			ft_error();
		curr = curr->next;
	}
}

int	ft_check_duplicates(t_list *lst)
{
	t_list	*curr;
	t_list	*next;

	curr = lst;
	if (!curr)
		return (1);
	while (curr->next)
	{
		next = curr->next;
		while (next)
		{
			if (ft_strcmp(curr->value, next->value) == 0)
				return (1);
			next = next->next;
		}
		curr = curr->next;
	}
	return (0);
}

int	ft_isint(char *l)
{
	long	n;
	long	sign;
	int		i;

	n = 0;
	sign = 1;
	i = 0;
	while (l[i] == ' ')
		i++;
	if (l[i] == '-' || l[i] == '+')
	{
		if (l[i] == '-')
			sign = -sign;
		i++;
	}
	while (ft_isdigit(l[i]))
	{
		n = (n * 10) + (l[i] - 48);
		if (n * sign > INT_MAX || n * sign < INT_MIN)
			return (0);
		i++;
	}
	while (l[i] == ' ')
		i++;
	return (l[i] == '\0');
}

void	ft_error(void)
{
	ft_putendl_fd("Error\n", 2);
	exit(EXIT_FAILURE);
}
