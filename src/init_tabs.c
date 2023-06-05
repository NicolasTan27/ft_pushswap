/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tabs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 18:33:01 by ntan              #+#    #+#             */
/*   Updated: 2022/02/09 17:15:53 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	*argv_to_tab(int size, char **argv)
{
	int	*res;
	int	i;

	i = 0;
	res = malloc(sizeof(char *) * (size));
	if (res == NULL)
		return (NULL);
	while (i < size)
	{
		res[i] = ft_atoi(argv[size - i]);
		i++;
	}
	return (res);
}

int	*init_b(int size)
{
	int	*res;

	res = malloc(sizeof(char *) * (size));
	if (res == NULL)
		return (NULL);
	return (res);
}

int	*create_sorted_tab(int size, char **argv)
{
	int	i;
	int	j;
	int	temp;
	int	*tab;

	tab = argv_to_tab(size, argv);
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

t_stack	*init_tabs(int argc, char **argv)
{
	t_stack	*res;

	res = malloc(sizeof(*res));
	if (res == NULL)
		return (NULL);
	res->stack_a = argv_to_tab(argc - 1, argv);
	if (res->stack_a == NULL)
	{
		free(res);
		return (NULL);
	}
	res->stack_b = init_b(argc - 1);
	if (res->stack_b == NULL)
	{
		free(res);
		free(res->stack_a);
		return (NULL);
	}
	res->size_a = argc - 1;
	res->size_b = 0;
	res->sorted_tab = create_sorted_tab(argc - 1, argv);
	res->size_sorted = argc - 1;
	return (res);
}

void	destroy(t_stack *s)
{
	free(s->stack_a);
	free(s->stack_b);
	free(s->sorted_tab);
	free(s);
}
