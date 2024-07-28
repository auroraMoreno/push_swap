/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aumoreno < aumoreno@student.42madrid.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 10:30:23 by aumoreno          #+#    #+#             */
/*   Updated: 2024/07/28 13:59:09 by aumoreno         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
	ft_print_list(a);
	if (should_free == 1)
		ft_free_arr(str_data);
	ft_lstclear(&a, NULL);
	ft_lstclear(&b, NULL);
	return (0);
}
