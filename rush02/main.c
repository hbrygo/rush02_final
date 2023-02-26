/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 10:19:03 by hubrygo           #+#    #+#             */
/*   Updated: 2023/02/25 16:10:10 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"rush02.h"

#define BUFFER_SIZE 1

char	*ft_strcat(char *dest, char src)
{
	int	i;

	i = -1;
	while (dest[++i])
		;
	dest[i] = src;
	i++;
	dest[i] = '\0';
	return (dest);
}

int	nbr_of_char(int argc, char **argv)
{
	int		i;
	int		fd;
	int		ret;
	char	buff[1];

	i = 0;
	ret = 1;
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret != 0)
	{
		i++;
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (close(fd) == -1)
		return (-1);
	return (i);
}

int	main(int argc, char **argv)
{
	int		fd;
	int		i;
	int		ret;
	char	buff[1];
	char	*str;

	ret = 1;
	i = nbr_of_char(argc, argv);
	if (i == -1)
		return (-1);
	str = malloc(sizeof(char) * i + 1);
	if (argc == 2)
		fd = open("numbers.dict", O_RDONLY);
	else
		fd = open(argv[2], O_RDONLY);
	if (fd == -1)
		return (-1);
	ret = read(fd, buff, BUFFER_SIZE);
	while (ret != 0)
	{
		str = ft_strcat(str, buff[0]);
		ret = read(fd, buff, BUFFER_SIZE);
	}
	if (close(fd) == -1)
		return (-1);
	str[i + 1] = '\0';
	ft_split(str, "\n", argv[1]);
	return (0);
}
