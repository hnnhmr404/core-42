/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:53:46 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/07 10:53:51 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (!dst || !src)
		return (NULL);
	if (dst > src)
		while (len--)
			*(char *)(dst + len) = *(char *)(src + len);
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
