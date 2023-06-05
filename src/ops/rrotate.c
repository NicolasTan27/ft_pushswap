/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 20:40:06 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 14:26:40 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	rrotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a >= 2)
	{
		temp = stack->stack_a[0];
		i = 0;
		while (i < stack->size_a)
		{
			stack->stack_a[i] = stack->stack_a[i + 1];
			i++;
		}
		stack->stack_a[stack->size_a - 1] = temp;
		ft_putstr_fd("rra\n", 1);
	}
}

void	rrotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_b >= 2)
	{
		temp = stack->stack_b[0];
		i = 0;
		while (i < stack->size_b)
		{
			stack->stack_b[i] = stack->stack_b[i + 1];
			i++;
		}
		stack->stack_b[stack->size_b - 1] = temp;
		ft_putstr_fd("rrb\n", 1);
	}
}

void	rrotate_ab(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_b >= 2 || stack->size_a >= 2)
	{
		if (stack->size_a >= 2)
		{
			temp = stack->stack_a[0];
			i = -1;
			while (++i < stack->size_a)
				stack->stack_a[i] = stack->stack_a[i + 1];
			stack->stack_a[stack->size_a - 1] = temp;
		}
		if (stack->size_b >= 2)
		{
			temp = stack->stack_b[0];
			i = -1;
			while (++i < stack->size_b)
				stack->stack_b[i] = stack->stack_b[i + 1];
			stack->stack_b[stack->size_b - 1] = temp;
		}
		ft_putstr_fd("rrr\n", 1);
	}
}
