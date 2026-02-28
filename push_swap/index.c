/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/28 12:45:14 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 12:45:42 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	*sorted_array_copy(t_stack *stack)
{
	int		*copy;
	size_t	size;

	size = stack->top + 1;
	copy = malloc(size * sizeof(*copy));
	ft_memcpy(copy, stack->array, size * sizeof(*copy));
	insertion_sort(copy, size);
	return (copy);
}

void	index_stack(t_stack **stack)
{
	int		*copy;
	int		i;
	size_t	pos;
	int		*array;

	i = 0;
	array = ft_calloc((*stack)->top + 1, sizeof(*array));
	copy = sorted_array_copy(*stack);
	while (i <= (*stack)->top)
	{
		pos = 0;
		while (copy[pos] != (*stack)->array[i])
			pos++;
		array[i++] = pos;
	}
	ft_memcpy((*stack)->array, array, ((*stack)->top + 1) * sizeof(*array));
	free(copy);
	free(array);
}

int	_index(t_stack *stack, int n)
{
	int	i;

	i = stack->top;
	while (stack->array[i] != n && i >= 0)
		i--;
	return (i);
}
