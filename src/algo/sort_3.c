/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/07 17:48:05 by ntan              #+#    #+#             */
/*   Updated: 2022/02/09 17:30:38 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	sort_3(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
		&& s->stack_a[1] < s->stack_a[2])
	{
		swap_a(s);
		rrotate_a(s);
	}
	if (s->stack_a[0] < s->stack_a[1] && s->stack_a[0] < s->stack_a[2]
		&& s->stack_a[1] > s->stack_a[2])
		rrotate_a(s);
	if (s->stack_a[1] < s->stack_a[0] && s->stack_a[1] < s->stack_a[2]
		&& s->stack_a[0] < s->stack_a[2])
		rotate_a(s);
	if (s->stack_a[1] < s->stack_a[0] && s->stack_a[1] < s->stack_a[2]
		&& s->stack_a[0] > s->stack_a[2])
		swap_a(s);
	if (s->stack_a[2] < s->stack_a[0] && s->stack_a[2] < s->stack_a[1]
		&& s->stack_a[1] > s->stack_a[0])
	{
		swap_a(s);
		rotate_a(s);
	}
}

void	sort_2(t_stack *s)
{
	if (s->stack_a[0] < s->stack_a[1])
		swap_a(s);
}
