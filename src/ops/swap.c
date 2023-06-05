/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 13:25:51 by ntan              #+#    #+#             */
/*   Updated: 2022/02/09 17:27:00 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	swap_a(t_stack *stack)
{
	int	temp;

	if (stack->size_a >= 2)
	{
		temp = stack->stack_a[stack->size_a - 1];
		stack->stack_a[stack->size_a - 1] = stack->stack_a[stack->size_a - 2];
		stack->stack_a[stack->size_a - 2] = temp;
		ft_putstr_fd("sa\n", 1);
	}
}

void	swap_b(t_stack *stack)
{
	int	temp;

	if (stack->size_b >= 2)
	{
		temp = stack->stack_b[stack->size_b - 1];
		stack->stack_b[stack->size_b - 1] = stack->stack_b[stack->size_b - 2];
		stack->stack_b[stack->size_b - 2] = temp;
		ft_putstr_fd("sb\n", 1);
	}
}

void	swap_ab(t_stack *stack)
{
	int	temp;

	if (stack->size_a >= 2 || stack->size_b >= 2)
	{
		if (stack->size_a >= 2)
		{
			temp = stack->stack_a[0];
			stack->stack_a[0] = stack->stack_a[1];
			stack->stack_a[1] = temp;
		}
		if (stack->size_b >= 2)
		{
			temp = stack->stack_b[0];
			stack->stack_b[0] = stack->stack_b[1];
			stack->stack_b[1] = temp;
		}
		ft_putstr_fd("ss\n", 1);
	}
}
