/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   smart.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:22:29 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 12:21:32 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	closest_above(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n > max(a))
		return (n);
	i = 0;
	k = max(a);
	while (i <= a->top)
	{
		if (a->array[i] > n && a->array[i] < k)
			k = a->array[i];
		i++;
	}
	return (k);
}

int	closest_below(t_stack *a, int n)
{
	int	k;
	int	i;

	if (a->top < 0 || n < min(a))
		return (n);
	i = 0;
	k = min(a);
	while (i <= a->top)
	{
		if (a->array[i] < n && a->array[i] > k)
			k = a->array[i];
		i++;
	}
	return (k);
}

void	smart_rotate_a(t_stack *a, int n)
{
	int	find;

	find = a->top;
	while (find >= 0 && a->array[find] != n)
		find--;
	if (find < 0)
		return ;
	else if (find < a->top / 2)
		run_n(RRA, a, NULL, find + 1);
	else
		run_n(RA, a, NULL, a->top - find);
}

void	smart_rotate_b(t_stack *b, int n)
{
	int	find;

	find = b->top;
	while (b->array[find] != n && find >= 0)
		find--;
	if (find < 0)
		return ;
	else if (find < b->top / 2)
		run_n(RRB, NULL, b, find + 1);
	else
		run_n(RB, NULL, b, b->top - find);
}
