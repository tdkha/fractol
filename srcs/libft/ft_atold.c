/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:26:00 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/14 16:53:31 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long double	float_section_handler(char **str)
{
	long double res;
	size_t		len;

	res = 0;
	while(**str && **str != '.')
		(*str)++;
	if (**str == '.')
	{
		(*str)++;
		res = (long double) ft_atoi(*str);
	}
	if (res != 0)
	{
		len = ft_strlen(*str);
		while (len--)
		{
			res /= 10;
		}
	}
	return (res);
}

long double	ft_atold(const char *s)
{
	char		*str;
	long double	int_section;
	long double	float_section;
	int			sign;

	sign = 1;
	str = ft_strtrim(s, " ");
	while (*str && ft_isspace(*s))
		str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	int_section = (long double) ft_atoi(str);
	float_section = float_section_handler(&str);
	return (sign * (int_section + float_section));
}
