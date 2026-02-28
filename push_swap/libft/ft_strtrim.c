/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 11:20:07 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 14:22:20 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	a;
	size_t	z;
	char	*s;

	if (!s1 || !set)
		return (0);
	a = 0;
	z = ft_strlen(s1);
	while (z > a && ft_strchr(set, s1[z - 1]))
		z--;
	while (a < z && ft_strchr(set, s1[a]))
		a++;
	s = malloc(sizeof(char) * (z - a + 1));
	if (!s)
		return (0);
	ft_strlcpy(s, s1 + a, z - a + 1);
	return (s);
}
