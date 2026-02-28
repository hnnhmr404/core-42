/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 17:03:05 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/11 17:03:14 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	size(int n)
{
	size_t	i;

	i = 1;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	int		neg;
	char	*res;

	i = (n <= 0) + size(n);
	neg = n < 0;
	res = malloc(sizeof(char) * i);
	if (res == 0)
		return (0);
	res[0] = '-';
	res[--i] = 0;
	if (!neg)
		n *= -1;
	while (--i >= neg)
	{
		res[i] = (n % 10 * -1) + '0';
		n /= 10;
	}
	return (res);
}
