/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:07:13 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/31 15:01:54 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft.h"
# include "mlx.h"

typedef struct s_img
{
	void	*wall;
	void	*player;
	void	*coins;
	void	*floor;
	void	*exit;
	int		h;
	int		w;
}	t_img;


typedef struct s_game
{
	void	*mlx;
	void	*win;
	char	**map;
	char	*map_width;
	char	*map_height;
	t_img	*img;
}	t_game;


int		check_map(char **map);
int		check_name(char *str);
void	print_game(t_game *game);
#endif