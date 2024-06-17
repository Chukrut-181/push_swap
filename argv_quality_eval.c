/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:29 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/14 11:41:03 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

long	ft_atoi(const char *str)
{
	long	result;
	int		sign;

	if (*str == '\0')
		ft_exit();
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
	return (result * sign);
}

void	ft_evaluate_quality(char **argv)
{
	int		i;
	int		j;
	int		k;

	i = 1;
	while (argv[i])
	{
		j = 0;
		while (argv[i][j])
		{
			if ((argv[i][j] < '0' && argv[i][j] != '-') || '9' < argv[i][j])
				ft_exit();
			if (j != 0 && argv[i][j] == '-')
				ft_exit();
			j++;
		}
		k = i + 1;
		while (argv[i] && argv[k])
		{
			if (!ft_strcmp(argv[i], argv[k]))
				ft_exit();
			k++;
		}
		i++;
	}
}

int	*ft_convert_to_int(int argc, char **argv)
{
	int		*num_str;
	long	v;
	int		i;

	num_str = malloc(argc * sizeof(int));
	if (!num_str)
		ft_exit();
	i = 1;
	while (i < argc)
	{
		v = ft_atoi(argv[i]);
		if (v < -2147483648 || 2147483647 < v)
		{
			free(num_str);
			ft_exit();
		}
		num_str[i - 1] = v;
		i++;
	}
	num_str[argc - 1] = '\0';
	return (num_str);
}

int	ft_strcmp(const char *s1, const char *s2)
{
	unsigned char	*ucs1;
	unsigned char	*ucs2;

	ucs1 = (unsigned char *)s1;
	ucs2 = (unsigned char *)s2;
	if (*ucs1 == '-' && *ucs2 == '-')
	{
		ucs1++;
		ucs2++;
	}
	while (*ucs1 == '0')
		ucs1++;
	while (*ucs2 == '0')
		ucs2++;
	while ((*ucs1 != '\0' || *ucs2 != '\0'))
	{
		if (*ucs1 > *ucs2)
			return (1);
		if (*ucs1 < *ucs2)
			return (-1);
		ucs1++;
		ucs2++;
	}
	return (0);
}
