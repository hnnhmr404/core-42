/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:13:43 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 16:47:12 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	n;
	char	*str;

	n = ft_strlen(s);
	if (start > n)
		return (ft_strdup(""));
	else if (start + len > n)
		len = n - start;
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (!str || !s)
		return (0);
	ft_strlcpy(str, s + start, len + 1);
	return (str);
}
