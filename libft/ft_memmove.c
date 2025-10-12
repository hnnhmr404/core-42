/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/07 10:53:46 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 15:58:20 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t len)
{
	if (!dest || !src)
		return (0);
	if (dest > src)
		while (len--)
			*(char *)(dest + len) = *(char *)(src + len);
	else
		ft_memcpy(dest, src, len);
	return (dest);
}
