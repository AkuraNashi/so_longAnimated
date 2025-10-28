/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:58:23 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/28 17:11:00 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_playable(char **map)
{
	(void)map;
	return (0);
}

int	check_rectangle(char **str)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = -1;
	while (str[i])
	{
		if (len)
		{
			if (len != ft_strlen(str[i]))
				return (0);
		}
		len = ft_strlen(str[i]);
		i++;
	}

	printf("len [%zu] i [%zu]\n", len, i);
	if (len == i)
		return (0);
	return (1);
}

int	check_name(char *str)
{
	char	*res;

	res = ft_strchr(str, '.');
	if (res)
	{
		if (ft_strcmp(".ber", res) == 0)
			return (1);
	}
	return (0);
}
int	check_map(char **map)
{
	if (!check_rectangle(map))
	{
		ft_putstr_fd("Error map is not rectangle\n", 2);
		return (0);
	}
	if (!check_playable(map))
	{
		ft_putstr_fd("Error map isn't playable\n", 2);
		return (0);
	}
	return (1);
}
