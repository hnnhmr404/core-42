/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rules2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:12:22 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/18 12:00:17 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*initialize(unsigned int size)
{
	t_stack	*stack;

	stack = malloc(sizeof(*stack));
	if (!(stack))
		return (NULL);
	stack->array = malloc(size * sizeof(*(stack->array)));
	if (!(stack->array))
		return (NULL);
	stack->size = size;
	stack->top = -1;
	return (stack);
}

int min(t_stack *stack)
{
	int i;
	int m;
	
	i = 0;
	m = stack->array[0];
	while (++i <= stack->top)
		if (stack->array[i] < m)
			m = stack->array[i];
	return (m);
}

int max(t_stack *stack)
{
	int i = 0;
	int m = stack->array[0];
	
	while (++i <= stack->top)
		if (stack->array[i] > m)
			m = stack->array[i];
	return (m);
}

