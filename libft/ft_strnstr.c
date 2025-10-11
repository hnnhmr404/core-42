/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:09:33 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/11 10:21:50 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *b, const char *s, size_t len)
{
	size_t	i;
	size_t	j;

	if (*s == '\0')
		return ((char *)b);
	i = 0;
	while (b[i] && i < len)
	{
		j = 0;
		while (b[i + j] && s[j] && b[i + j] == s[j] && (i + j) < len)
			j++;
		if (s[j] == '\0')
			return ((char *)s[i]);
		i++;
	}
	return (0);
}
