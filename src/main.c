/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lecamilo <lecamilo@42lausanne.ch>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/15 14:06:40 by lecamilo          #+#    #+#             */
/*   Updated: 2025/10/15 19:34:50 by lecamilo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	count_line(int fd)
{
	char	*line;
	int		count;

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
	printf("count : [%d]\n", count);
	return (count);
}

char	**get_map(char *file)
{
	int		fd;
	char	**map;

	fd = open(file, O_RDONLY);
	if (fd == 0 || fd < 0)
		return (NULL);
	printf("get_map : [%s]\n", get_next_line(fd));
	// count_line(fd);
	(void)map;
	// map = malloc(sizeof(char *) * (count_line(fd) + 1));
	return (NULL);
}

void	init_game(t_game *game, char *file)
{
	game->map = get_map(file);
	// game->mlx = mlx_init();
	// game->win = mlx_new_window(game->mlx, 1000, 1000, "42Bureau");
}

int	main(int ac, char **av)
{
	t_game	game;

	if (ac == 2)
	{
		if (!check_map(av[1]))
		{
			ft_putstr_fd("Error with map file\n", 2);
			return (1);
		}
		init_game(&game, av[1]);
		// mlx_loop(game.mlx);
	}
	else
		printf("Usage : ./so_long MAP.ber\n");
	(void) av;
	return (1);
}
