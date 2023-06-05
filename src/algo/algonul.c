/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algonul.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:37:11 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 14:27:12 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	find_dir(t_stack *s, int val)
{
	int	i;

	i = 0;
	while (i < s->size_a)
	{
		if (s->stack_a[i] == val)
			break ;
		i++;
	}
	if (i > s->size_a / 2)
		rotate_a(s);
	else
		rrotate_a(s);
}

void	sort_to_b(t_stack *s, int i, int swap)
{
	i = s->size_sorted - 1;
	while (i > 2)
	{
		if (s->sorted_tab[i] == s->stack_a[s->size_a - 1])
		{
			push_to_b(s);
			i--;
			if (swap == 1)
			{
				swap_b(s);
				i--;
				swap = 0;
			}
		}
		else if (i > 3 && swap == 0
			&& s->sorted_tab[i - 1] == s->stack_a[s->size_a - 1])
		{
			push_to_b(s);
			swap = 1;
		}
		else
			find_dir(s, s->sorted_tab[i]);
	}
}

void	algonul(t_stack *s)
{
	int	i;
	int	swap;

	i = 0;
	swap = 0;
	sort_to_b(s, i, swap);
	sort_3(s);
	while (s->size_b)
		push_to_a(s);
}
