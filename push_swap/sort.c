/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 20:32:24 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 12:21:44 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort(t_stack *stack)
{
	t_stack	*new;

	if (is_sorted(stack) || stack->top <= 0)
		return ;
	new = initialize(stack->size);
	if (stack->top < SORT_COMPLEX_LIMIT)
		sort_small(stack, new);
	else
		sort_complex(stack, new);
	free_stack(new);
}
