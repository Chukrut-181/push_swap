/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:29 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/12 14:16:12 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || (9 <= *str && *str <= 13))
		str++;
	if (*str == '-' || *str == '+')
	{
		if (*str == '-')
			sign = (sign * -1);
		str++;
	}
	while ('0' <= *str && *str <= '9')
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	result = result * sign;
	if (result < -2147483648 || result > 2147483647)
		exit (write(1, "Error\n", 6));
	return (result);
}

int	ft_evaluate_quality(char **argv)
{
	int		i;
	int		j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' && argv[i][j] != '-') || '9' < argv[i][j])
				return (0);
			if (j != 0 && argv[i][j] == '-')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
