/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tmp.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 18:58:23 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/15 19:19:57 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_map(char *str)
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
