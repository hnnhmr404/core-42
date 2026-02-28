/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:06:36 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 15:49:13 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total;
	void	*ptr;

	if (size != 0 && count > ((size_t)-1) / size)
		return (0);
	total = count * size;
	ptr = malloc(total);
	if (ptr == NULL)
		return (0);
	ft_bzero(ptr, total);
	return (ptr);
}
