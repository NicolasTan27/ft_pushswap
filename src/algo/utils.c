/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 14:35:56 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 22:24:30 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../pushswap.h"

int	*bubble_sort(int *tab, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i++ < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] < tab[j + 1])
			{
				temp = tab[j];
				tab[j] = tab[j + 1];
				tab[j + 1] = temp;
			}
			j++;
		}
	}
	return (tab);
}

int	abs(int value)
{
	if (value < 0)
		return (value * -1);
	else
		return (value);
}

int	correct_pos(int value, int size)
{
	if (value > size / 2)
		return (value - size);
	else
		return (value);
}
