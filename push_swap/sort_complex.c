/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_complex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/02 15:44:50 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/18 11:59:27 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	put_in_position(t_stack *a, t_stack *b)
{
	int	top_b;
	int	to_move;

	top_b = b->array[b->top];
	to_move = closest_above(a, top_b);
	if (to_move == top_b && a->top >= 0)
		to_move = min(a);
	smart_rotate_a(a, to_move);
	run(PA, a, b);
}

static void	sort_chunk(t_stack *a, t_stack *b)
{
	while (b->top >= 0)
	{
		move_min_or_max_to_top(b);
		put_in_position(a, b);
	}
}

static void	move_chunk(t_stack *a, t_stack *b, int min, int max)
{
	int	size;

	size = max - min + 1;
	while (size)
	{
		move_to_top(a, min, max);
		run(PB, a, b);
		size--;
	}
}

static size_t	get_chunks(t_stack *a)
{
	size_t	chunks;

	chunks = (a->top + 1) / CHUNK_CONSTANT + 1;
	return (chunks);
}

void	sort_complex(t_stack *a, t_stack *b)
{
	int		limit_min;
	int		limit_max;
	size_t	chunks;
	size_t	step;

	chunks = get_chunks(a);
	limit_max = max(a);
	step = (a->top + 1) / chunks;
	while (chunks >= 1)
	{
		if (chunks == 1)
			limit_min = min(a);
		else
			limit_min = limit_max - step + 1;
		move_chunk(a, b, limit_min, limit_max);
		sort_chunk(a, b);
		limit_max = limit_min - 1;
		chunks--;
	}
	smart_rotate_a(a, min(a));
}
