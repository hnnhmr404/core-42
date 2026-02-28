/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hbinti-d <hbinti-d@student.42iskandar      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/11 09:06:01 by hbinti-d          #+#    #+#             */
/*   Updated: 2025/10/12 17:03:50 by hbinti-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *nptr)
{
	int	neg;
	int	res;

	res = 0;
	neg = 1;
	while ((*nptr >= '\t' && *nptr <= '\r') || *nptr == 32)
		nptr++;
	if (*nptr == '-')
		neg = -1;
	if (*nptr == '+' || *nptr == '-')
		nptr++;
	while (*nptr >= '0' && *nptr <= '9')
		res = (res * 10) + (*(nptr++) - '0');
	return (res * neg);
}
