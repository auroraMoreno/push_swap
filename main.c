/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:30:23 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/29 00:17:24 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_issorted(t_list *numbers)
{
	t_list	*curr;

	if (!numbers)
		return (0);
	curr = numbers;
	while (curr->next)
	{
		if (ft_atoi(curr->value) > ft_atoi(curr->next->value))
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	ft_select_alg(t_list **a, t_list **b)
{
	if (ft_lstsize(*a) == 2)
		ft_swap_a(*a);
	else if (ft_lstsize(*a) == 3)
		ft_sort_three(a, b);
	else if (ft_lstsize(*a) == 4)
		ft_sort_four(a, b);
	else if (ft_lstsize(*a) == 5)
		ft_sort_five(a, b);
	else
		ft_do_alg(a, b);
}

void	ft_do_alg(t_list **a, t_list **b)
{
	int	*segments;

	segments = ft_generate_segments(*a);
	ft_move_to_b(a, b, segments);
	ft_move_to_a(a, b);
	free(segments);
}

void	ft_clear_lists(t_list *a, t_list *b)
{
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
}

int	main(int argc, char **argv)
{
	t_list	*a;
	t_list	*b;
	char	**str_data;
	int		should_free;

	should_free = 0;
	if (argc < 2 || (argc == 2 && !argv[1][0]))
		return (ft_putendl_fd("Error", 2), 0);
	else if (argc == 2)
	{
		str_data = ft_split(argv[1], ' ');
		should_free = 1;
	}
	else
		str_data = argv + 1;
	a = ft_insert_initial(str_data, 0);
	b = NULL;
	ft_error_checking(a);
	if (ft_issorted(a) == 1)
		exit(EXIT_SUCCESS);
	ft_select_alg(&a, &b);
	if (should_free == 1)
		ft_free_arr(str_data);
	ft_clear_lists(a, b);
	return (0);
}
