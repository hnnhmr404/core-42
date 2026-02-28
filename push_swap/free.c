/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/29 19:11:58 by hbinti-d          #+#    #+#             */
/*   Updated: 2026/02/28 11:46:00 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_array(void **array)
{
	size_t	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_stack(t_stack *stack)
{
	free(stack->array);
	free(stack);
}

void	message_and_exit(t_stack *stack, char **ops, int status)
{
	if (stack)
		free_stack(stack);
	if (ops)
		free_array((void **)ops);
	ft_putstr_fd("Error\n", STDERR_FILENO);
	exit(status);
}
