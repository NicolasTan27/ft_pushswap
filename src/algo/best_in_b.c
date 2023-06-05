/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_in_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/28 13:24:18 by ntan              #+#    #+#             */
/*   Updated: 2022/03/07 12:51:04 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

int	find_dest_in_a(int *tab, int size, int value)
{
	int	i;
	int	max;
	int	max_ind;

	i = -1;
	while (++i < size - 1)
	{
		if (i == 0 && value > tab[0] && value < tab[size - 1])
			return (0);
		else if (value < tab[i] && value > tab[i + 1])
			return (correct_pos(i + 1, size));
	}
	i = -1;
	max = -2147483648;
	while (++i < size)
	{		
		if (tab[i] > max)
		{
			max = tab[i];
			max_ind = i;
		}
	}
	return (correct_pos(max_ind, size));
}

void	exec_combo_2(t_stack *s, int *combo)
{
	while (combo[0] > 0)
	{
		rrotate_a(s);
		combo[0]--;
	}
	while (combo[0] < 0)
	{
		rotate_a(s);
		combo[0]++;
	}
	while (combo[1] > 0)
	{
		rrotate_b(s);
		combo[1]--;
	}
	while (combo[1] < 0)
	{
		rotate_b(s);
		combo[1]++;
	}
}

void	exec_combo(t_stack *s, int *combo)
{
	while (combo[0] > 0 && combo[1] > 0)
	{
		rrotate_ab(s);
		combo[0]--;
		combo[1]--;
	}
	while (combo[0] < 0 && combo[1] < 0)
	{
		rotate_ab(s);
		combo[0]++;
		combo[1]++;
	}
	exec_combo_2(s, combo);
}

void	best_in_b(t_stack *s)
{
	int	i;
	int	*combo;
	int	temp[2];

	combo = malloc(sizeof(int) * 2);
	combo[0] = find_dest_in_a(s->stack_a, s->size_a, s->stack_b[0]);
	combo[1] = s->size_b;
	i = -1;
	while (++i < s->size_b)
	{
		temp[0] = find_dest_in_a(s->stack_a, s->size_a, s->stack_b[i]);
		temp[1] = correct_pos(i + 1, s->size_b);
		if (abs(temp[0]) + abs(temp[1]) < abs(combo[0]) + abs(combo[1]))
		{
			combo[0] = temp[0];
			combo[1] = temp[1];
		}
	}
	exec_combo(s, combo);
	push_to_a(s);
	free(combo);
}
