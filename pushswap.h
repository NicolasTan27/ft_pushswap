/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ntan <ntan@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 17:13:20 by ntan              #+#    #+#             */
/*   Updated: 2022/02/28 22:24:14 by ntan             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_stack
{
	int	*stack_a;
	int	size_a;
	int	*stack_b;
	int	size_b;
	int	*sorted_tab;
	int	size_sorted;
}				t_stack;

int		check_arg(int argc, char **argv);
t_stack	*init_tabs(int argc, char **argv);
void	destroy(t_stack *s);
void	swap_a(t_stack *stack);
void	swap_b(t_stack *stack);
void	swap_ab(t_stack *stack);
void	push_to_b(t_stack *stack);
void	push_to_a(t_stack *stack);
void	rotate_a(t_stack *stack);
void	rotate_b(t_stack *stack);
void	rotate_ab(t_stack *stack);
void	rrotate_a(t_stack *stack);
void	rrotate_b(t_stack *stack);
void	rrotate_ab(t_stack *stack);
void	sort_3(t_stack *s);
void	sort_2(t_stack *s);
void	algonul(t_stack *s);
void	mix(t_stack *s);
void	lis(t_stack *s);
void	best_in_b(t_stack *s);
int		abs(int value);
int		correct_pos(int value, int size);

#endif