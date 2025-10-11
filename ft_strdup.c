/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:32:19 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/11 10:24:02 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

char	*ft_strdup(char *src)
{
	char	*dest;
	int		i;
	int		length;

	length = 0;
	while (src[length])
		length++;
	dest = (char *) malloc(sizeof(char) * (length + 1));
	if (dest == '\0')
		return (0);
	i = 0;
	while (i < length)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}
