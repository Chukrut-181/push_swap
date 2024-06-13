/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: igchurru <igchurru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/10 10:54:29 by igchurru          #+#    #+#             */
/*   Updated: 2024/06/13 15:54:02 by igchurru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_atoi(const char *str)
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
		i++;
	}
}

void	ft_exit(void)
{
	write(1, "Error\n", 6);
	exit (0);
}

int	*ft_convert_to_int(int argc, char **argv)
{
	int	*num_str;
	int	v;
	int	i;
	num_str = malloc(argc * sizeof(int));
	if (!num_str)
		ft_exit();
	i = 1;
	while (i < argc)
	{
		v = ft_atoi(argv[i]);
		if ((v < 0 && argv[i][0] != '-') || (v > 0 && argv[i][0] == '-'))
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
