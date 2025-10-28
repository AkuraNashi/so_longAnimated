/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:07:13 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/28 17:10:10 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*map_width;
	char	*map_height;
}	t_game;


int	check_map(char **map);
int		check_name(char *str);
#endif