/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lis.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/26 17:12:22 by ntan              #+#    #+#             */
/*   Updated: 2022/02/09 17:28:47 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

int	is_in_tab(int *tab, int size, int val)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] == val)
			return (1);
		i++;
	}
	return (0);
}

int	get_max(int *tab, int size)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (i < size)
	{
		if (tab[i] > max)
			max = tab[i];
		i++;
	}
	return (max);
}

int	*gen_lis(int *tab, int size)
{
	int	i;
	int	j;
	int	*lis;

	lis = malloc(sizeof(int) * size);
	if (lis == NULL)
		return (NULL);
	i = 1;
	j = -1;
	while (++j < size)
		lis[j] = 1;
	while (i < size)
	{
		j = 0;
		while (j < i)
		{
			if (tab[i] < tab[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;
			j++;
		}
		i++;
	}
	i = -1;
	return (lis);
}

int	*lis_2(int *tab, int size, int *j)
{
	int	i;
	int	*lis;
	int	max;
	int	*res;

	lis = gen_lis(tab, size);
	max = get_max(lis, size);
	res = malloc(sizeof(int) * max);
	if (res == NULL)
		return (0);
	i = size;
	*j = max;
	while (i--)
	{
		if (lis[i] == max)
		{
			res[max - 1] = tab[i];
			max--;
		}
	}
	free(lis);
	return (res);
}

void	lis(t_stack *s)
{
	int	*keep_tab;
	int	size_keep;

	size_keep = 0;
	keep_tab = lis_2(s->stack_a, s->size_a, &size_keep);
	while (s->size_a != size_keep)
	{
		if (is_in_tab(keep_tab, size_keep, s->stack_a[s->size_a - 1]) == 0)
			push_to_b(s);
		else
			rotate_a(s);
	}
	free(keep_tab);
}
