/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/06 19:40:48 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 14:26:49 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	rotate_a(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a >= 2)
	{
		temp = stack->stack_a[stack->size_a - 1];
		i = stack->size_a;
		while (i-- > 1)
			stack->stack_a[i] = stack->stack_a[i - 1];
		stack->stack_a[0] = temp;
		ft_putstr_fd("ra\n", 1);
	}
}

void	rotate_b(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_b >= 2)
	{
		temp = stack->stack_b[stack->size_b - 1];
		i = stack->size_b;
		while (i-- > 1)
			stack->stack_b[i] = stack->stack_b[i - 1];
		stack->stack_b[0] = temp;
		ft_putstr_fd("rb\n", 1);
	}
}

void	rotate_ab(t_stack *stack)
{
	int	temp;
	int	i;

	if (stack->size_a >= 2 && stack->size_b >= 2)
	{
		if (stack->size_a >= 2)
		{
			temp = stack->stack_a[stack->size_a - 1];
			i = stack->size_a;
			while (i-- > 1)
				stack->stack_a[i] = stack->stack_a[i - 1];
			stack->stack_a[0] = temp;
		}
		if (stack->size_b >= 2)
		{
			temp = stack->stack_b[stack->size_b - 1];
			i = stack->size_b;
			while (i-- > 1)
				stack->stack_b[i] = stack->stack_b[i - 1];
			stack->stack_b[0] = temp;
		}
		ft_putstr_fd("rr\n", 1);
	}
}
