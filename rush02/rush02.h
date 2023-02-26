/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rush02.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hubrygo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/25 16:10:45 by hubrygo           #+#    #+#             */
/*   Updated: 2023/02/25 16:10:47 by hubrygo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RUSH_02_H
# define RUSH_02_H

#include<unistd.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<fcntl.h>
#include<stdio.h>

char	*ft_strcat(char *dest, char src);
int	ft_error_argvalue(int argvalue);
int	ft_check(char c);
int	ft_atoi(char *str);
int	ft_error_atoi(char **c);
int	next_sep(char *str, char *charset);
int	ft_strlen(char *str);
char	**ft_split(char *str, char *charset, char *argv);
void	ft_int_words(char **c, unsigned int a);
char	*ft_strcpy(char *dest, char *src);
int	power(int length);
int	ft_check_atoi(char c, int check);
char	*reverse_string(char *c);

#endif