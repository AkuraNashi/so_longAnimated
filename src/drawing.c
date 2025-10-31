/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/31 14:44:14 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/31 15:54:40 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_image(t_game *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx, game->win, img, x * 32, y * 32);
}

void	print_game(t_game *game)
{
	char	**map;
	int		x;
	int		y;

	map = game->map;
	x = 0;
	while (map[x])
	{
		y = 0;
		while (map[x][y])
		{
			if (map[x][y] == '1')
				draw_image(game, game->img->wall, y, x);
			else if (map[x][y] == '0')
				draw_image(game, game->img->floor, y, x);
			y++;
		}
		x++;
	}
}
