/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_words.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbouaiss <bbouaiss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 13:31:22 by bbouaiss          #+#    #+#             */
/*   Updated: 2023/02/26 15:12:40 by bbouaiss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"

char	*reverse_string(char *c)
{
	char	*temp;
	int		count;
	int		count2;

	count = 0;
	count2 = 0;
	while (c[count] != '\0')
		count++;
	while (count != -1)
	{
		temp[count2] = temp[count];
		count2++;
		count--;
	}
	temp[count2] = '\0';
	return (temp);
}

int	ft_check_atoi(char c, int check)
{
	if (check == 1)
	{
		if (c == ' ' || c == '\f' || c == '\n')
			return (1);
		if (c == '\r' || c == '\t' || c == '\v')
			return (1);
		return (0);
	}
	else
	{
		if (c < 'A')
			return (0);
		else if (c > 'Z' && c < 'a')
			return (0);
		else if (c > 'z')
			return (0);
		else
			return (1);
	}
}

char	*last_word(char *str)
{
	int		i;
	int		b;
	char	*ret;

	i = 0;
	b = 0;
	while (str[i] != '\0')
		i++;
	b = i;
	i -= 1;
	while (str[i] != ' ')
		i--;
	i++;
	b -= i;
	ret = malloc(sizeof(char) * b);
	ret[0] = '\0';
	while (str[i] != '\0')
	{
		ret = ft_strcat(ret, str[i]);
		i++;
	}
	return (ret);
}

////////////////
int	power(int length)
{
	int	result;

	result = 1;
	while (--length != 0)
	{
		result = result * 10;
	}
	return (result);
}

int	ft_intlen(int nmbr)
{
	int	result;

	result = 1;
	while (nmbr != 0)
	{
		nmbr = nmbr / 10;
		result++;
	}
	result--;
	return (result);
}

void	ft_int_words(char **c, unsigned int a)
{
	char				*result;
	unsigned int		count;
	unsigned int		temp;
	unsigned int		i;

	count = 0;
	temp = 0;
	i = ft_atoi(c[count]);
	if (a > 4294967295)
		return ;
	printf("the value i found in dict: %d\n\n\n\n", ft_intlen(ft_atoi(c[count-1])));
	while (a > i)
	{
		count++;
		i = ft_atoi(c[count]);
	}
	if (a == i)
	{
		result = last_word(c[count]);
		i = -1;
		while (result[++i])
			write(1, &result[i], 1);
		return ;
	}
	else if (ft_intlen(ft_atoi(c[count])) == 10)
	{
		temp = a / 1000000000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = 1000000000;
		a = a % 1000000000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		ft_int_words(c, a);
	}
	else if (ft_intlen(ft_atoi(c[count - 1])) == 7)
	{
		temp = a / 1000000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = 1000000;
		a = a % 1000000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		ft_int_words(c, a);
	}
	else if (ft_intlen(ft_atoi(c[count - 1])) == 5)
	{
		temp = a / 10000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = 10000;
		a = a % 10000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		ft_int_words(c, a);
	}
	else if (ft_intlen(ft_atoi(c[count - 1])) == 4)
	{
		temp = a / 1000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = 1000;
		a = a % 1000;
		ft_int_words(c, temp);
		write(1, " ", 1);
		ft_int_words(c, a);
	}
	else if (ft_intlen(ft_atoi(c[count - 1])) == 3)
	{
		temp = a / 100;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = 100;
		a = a % 100;
		ft_int_words(c, temp);
		write(1, " ", 1);
		ft_int_words(c, a);
	}
	else if (ft_intlen(ft_atoi(c[count - 1])) <= 2)
	{	
		temp = (a / 10) * 10;
		ft_int_words(c, temp);
		write(1, " ", 1);
		temp = a % 10;
		ft_int_words(c, temp);
		return ;
	}
	return ;
}

char	*ft_strcpy(char *dest, char *src)
{
	int	count;

	count = 0;
	while (src[count] != '\0')
	{
		dest[count] = src[count];
		count++;
	}
	dest[count] = '\0';
	return (dest);
}
