/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:11:47 by ntan              #+#    #+#             */
/*   Updated: 2022/03/08 14:29:41 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	check(t_stack *stack)
{
	int	i;

	i = 0;
	while (i < stack->size_sorted)
	{
		if (stack->stack_a[i] != stack->sorted_tab[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_stack	*res;

	if (argc >= 2)
	{
		res = init_tabs(argc, argv);
		if (check_arg(argc, argv) == 1)
		{
			if (check(res) == 1)
				;
			else if (res->size_a == 2)
				sort_2(res);
			else if (res->size_a == 3)
				sort_3(res);
			else if (res->size_a < 10)
				algonul(res);
			else
				mix(res);
		}
		else
			ft_putstr_fd("Error\n", 2);
		destroy(res);
	}
	return (0);
}
