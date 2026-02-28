/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:07:37 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 16:49:24 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_spliter(char *s, size_t num, size_t len)
{
	size_t	i;
	size_t	j;
	char	**str;

	i = 0;
	j = 0;
	str = ft_calloc((num + 1), sizeof(char *));
	if (str == 0)
		return (0);
	else if (s[i] != '\0')
		str[j++] = ft_strdup(&s[i]);
	while (i++ < len)
		if (s[i] != '\0' && s[i - 1] == '\0')
			str[j++] = ft_strdup(&s[i]);
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	num;
	size_t	len;
	char	*str;
	char	**spl;

	i = -1;
	num = 0;
	len = ft_strlen(s);
	str = ft_strdup(s);
	if (str == NULL)
		return (NULL);
	while (++i < len)
	{
		if (str[i] == c)
			str[i] = '\0';
		else if (i == 0 || str[i - 1] == '\0')
			num++;
	}
	spl = ft_spliter(str, num, len);
	free(str);
	return (spl);
}
