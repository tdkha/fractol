/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atold.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ktieu <ktieu@student.hive.fi>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 15:26:00 by ktieu             #+#    #+#             */
/*   Updated: 2024/06/16 23:49:55 by ktieu            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static inline void	ft_atold_malloc_err(char *str)
{
	if (!str)
	{
		printf("ft_atold: Malloc error in ft_strtrim\n");
		exit(1);
	}
}

long double	float_section_handler(char **str)
{
	long double	res;
	size_t		len;

	res = 0.0;
	len = 0;
	while (**str && **str != '.')
	{
		(*str)++;
	}
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
			res /= 10.0;
		}
	}
	return (res);
}

long double	ft_atold(const char *s)
{
	char		*start;
	char		*str;
	long double	int_section;
	long double	float_section;
	int			sign;

	sign = 1;
	str = ft_strtrim(s, " ");
	if (!str)
		ft_atold_malloc_err(str);
	start = str;
	while (*str && ft_isspace(*str))
		str++;
	while (*str && (*str == '-' || *str == '+'))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	int_section = (long double) ft_atoi(str);
	float_section = float_section_handler(&str);
	free(start);
	return (sign * (int_section + float_section));
}
