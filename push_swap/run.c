/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:11:40 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 12:09:22 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	run(char *op, t_stack *a, t_stack *b)
{
	if (ft_strncmp(op, "pa", 3) == 0)
		push(b, a);
	else if (ft_strncmp(op, "pb", 3) == 0)
		push(a, b);
	else if (ft_strncmp(op, "sa", 3) == 0)
		swap(a);
	else if (ft_strncmp(op, "sb", 3) == 0)
		swap(b);
	else if (ft_strncmp(op, "ra", 3) == 0)
		rotate(a);
	else if (ft_strncmp(op, "rb", 3) == 0)
		rotate(b);
	else if (ft_strncmp(op, "rra", 4) == 0)
		reverse_rotate(a);
	else if (ft_strncmp(op, "rrb", 4) == 0)
		reverse_rotate(b);
	ft_putendl_fd(op, STDOUT_FILENO);
}

void	run_n(char *op, t_stack *a, t_stack *b, int n)
{
	if (n <= 0)
		return ;
	run(op, a, b);
	run_n(op, a, b, n - 1);
}
