/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:13:43 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/11 10:23:48 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;

	if (s == '\0')
		return (0);
	n = ft_strlen(s);
	else if (start >= n)
		len = n - start;
	str = malloc(len +1);
	if (str == '\0')
		return (0);
	ft_strlcpy(str, s + start len + 1);
	return (str);
}
