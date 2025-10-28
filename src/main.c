/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:06:40 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/28 17:09:47 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(char *file)
{
	char	*line;
	int		count;
	int		fd;

	fd = open(file, O_RDONLY);
	if (fd == 0 || fd < 0)
		return (-1);
	line = get_next_line(fd);
	count = 0;
	while (line)
	{
		count++;
		free(line);
		line = NULL;
		line = get_next_line(fd);
	}
	free(line);
	return (count);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;
	int		i;
	int		j;

	i = count_line(file);
	if (i < 0)
		return (NULL);
	map = malloc(sizeof(char *) * (i + 1));
	j = 0;
	fd = open(file, O_RDONLY);
	if (fd == 0 || fd < 0)
		return (NULL);
	while (j < i)
	{
		map[j] = ft_strtrim(get_next_line(fd), "\n");
		j++;
	}
	map[j] = NULL;
	j = 0;
	while (map[j])
	{
		printf("map [%s]\n", map[j]);
		j++;
	}
	return (map);
}

void	init_game(t_game *game, char *file)
{
	char	**map;

	if (!check_name(file))
		ft_putstr_fd("Error with map extension\n", 2);
	map = get_map(file);
	if (!check_map(map))
	{
		ft_putstr_fd("Error with map\n", 2);
	}
	game->map = map;
	// game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, 1000, 1000, "42Bureau");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{

		init_game(&game, av[1]);
		// mlx_loop(game.mlx);
	}
	else
		printf("Usage : ./so_long MAP.ber\n");
	(void) av;
	return (1);
}
