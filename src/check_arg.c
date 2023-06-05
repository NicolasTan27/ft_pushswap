/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_arg.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:38:08 by ntan              #+#    #+#             */
/*   Updated: 2022/05/09 15:38:33 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	int	i;

	i = 0;
	while (s1[i] || s2[i])
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
		i++;
	}
	return (0);
}

int	check_double(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc - 1)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_strcmp(argv[i], argv[j]) == 0)
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

int	is_only_digit(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && str[i] == '-')
			i++;
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

long long int	ft_atoi_long(const char *nptr)
{
	long long int	i;
	long long int	res;
	long long int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while ((nptr[i] >= 9 && nptr[i] <= 13) || nptr[i] == ' ')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (nptr[i] <= '9' && nptr[i] >= '0' && nptr[i])
	{
		res = res * 10 + nptr[i] - 48;
		i++;
	}
	return (res * sign);
}

int	check_arg(int argc, char **argv)
{
	int	i;

	i = 1;
	if (check_double(argc, argv))
		return (-1);
	while (i < argc)
	{
		if (!is_only_digit(argv[i])
			|| (ft_atoi_long(argv[i]) > 2147483647)
			|| (ft_atoi_long(argv[i]) < -2147483648)
			|| (ft_strcmp(argv[i], "") == 0)
			|| ft_strlen(argv[i]) > 19)
		{
			return (-1);
		}
		i++;
	}
	return (1);
}
