/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mix.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 13:02:25 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 12:54:02 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

void	find_dir(t_stack *s, int val);

void	find_dir_a(t_stack *s, int val)
{
	int	i;

	i = 0;
	while (i < s->size_b)
	{
		if (s->stack_b[i] == val)
			break ;
		i++;
	}
	if (i > s->size_b / 2)
		rotate_b(s);
	else
		rrotate_b(s);
}

void	mix(t_stack *s)
{
	lis(s);
	while (s->size_b)
		best_in_b(s);
	while (s->sorted_tab[s->size_sorted - 1] != s->stack_a[s->size_a - 1])
		find_dir(s, s->sorted_tab[s->size_sorted - 1]);
}
