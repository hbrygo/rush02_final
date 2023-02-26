/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouaiss <bbouaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 09:53:39 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/02/25 15:54:39 by plimbour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>*/
#include"rush02.h"

int	ft_error_argvalue(int argvalue)
{
	if (argvalue < 0)
		return (0);
	return (1);
}

int	ft_check(char c)
{
	if (c == ' ' || c == '\f' || c == '\n')
		return (1);
	if (c == '\r' || c == '\t' || c == '\v')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	result;
	int	sign;

	result = 0;
	sign = 1;
	while (*str == ' ' || *str == '\t' || *str == '\n'
		|| *str == '\r' || *str == '\v' || *str == '\f')
		str++;
	while (*str == '+' || *str == '-')
	{
		if (*str == '+')
			str++;
		else if (*str == '-')
		{
			sign *= -1;
			str++;
		}
	}
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}

int	ft_error_atoi(char **c)
{
	int	count;

	count = 0;
	while (c[count][0] != '\0')
	{
		if (ft_atoi(c[count]) < 0)
			return (0);
		if (ft_atoi(c[count]) > 2 && ft_atoi(c[count + 1]) != 0)
			return (0);
		count++;
	}
	return (1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
		;
	return (i);
}
