/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/29 14:04:53 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 14:26:21 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	push_to_b(t_stack *stack)
{
	if (stack->size_a > 0)
	{
		stack->size_b += 1;
		stack->stack_b[stack->size_b - 1] = stack->stack_a[stack->size_a - 1];
		stack->stack_a[stack->size_a - 1] = 0;
		stack->size_a -= 1;
		ft_putstr_fd("pb\n", 1);
	}
}

void	push_to_a(t_stack *stack)
{
	if (stack->size_b > 0)
	{
		stack->size_a += 1;
		stack->stack_a[stack->size_a - 1] = stack->stack_b[stack->size_b - 1];
		stack->stack_b[stack->size_b - 1] = 0;
		stack->size_b -= 1;
		ft_putstr_fd("pa\n", 1);
	}
}
