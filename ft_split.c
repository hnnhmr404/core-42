/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:07:37 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/11 17:07:48 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void free_all(char **arr, size_t j)
{
	while (j--)
		free(arr[j]);
	free(arr);
}

static char	**ft_spliter(char *s, size_t num, size_t len)
{
	size_t	i = 0;
	size_t	j = 0;
	char	**str = ft_calloc(num + 1, sizeof(char *));
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (s[i] != '\0' && (i == 0 || s[i - 1] == '\0'))
		{
			str[j] = ft_strdup(&s[i]);
			if (!str[j])
			{
				free_all(str, j);
				return (NULL);
			}
			j++;
		}
		i++;
	}
	str[j] = NULL;
	return (str);
}

char	**ft_split(char const *s, char c)
{
	size_t	i = 0;
	size_t	num = 0;
	size_t	len;
	char	*str;
	char	**spl;

	if (!s)
		return (NULL);
	len = ft_strlen(s);
	str = ft_strdup(s);
	if (!str)
		return (NULL);
	while (i < len)
	{
		if (str[i] == c)
			str[i] = '\0';
		else if (i == 0 || str[i - 1] == '\0')
			num++;
		i++;
	}
	spl = ft_spliter(str, num, len);
	free(str);
	return (spl);
}
