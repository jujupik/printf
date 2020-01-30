/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_basic.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jrouchon <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/26 17:00:48 by jrouchon          #+#    #+#             */
/*   Updated: 2020/01/26 17:00:50 by jrouchon         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_strcat(char *s1, char *s2)
{
	ft_strncat(s1, s2, ft_strlen(s2));
}

void	ft_strncat(char *s1, char *s2, size_t len)
{
	size_t	i;
	size_t	j;

	i = ft_strlen(s1);
	j = 0;
	while (j < len)
	{
		s1[i + j] = s2[j];
		j++;
	}
	s1[i + j] = '\0';
}

char	*fill(char *str, char c, int i)
{
	str[i] = '\0';
	i--;
	while (i >= 0)
	{
		str[i] = c;
		i--;
	}
	return (str);
}

char	*ft_strnew_c(size_t len, char c)
{
	char	*result;

	result = ft_strnew(len);
	fill(result, c, len);
	return (result);
}
