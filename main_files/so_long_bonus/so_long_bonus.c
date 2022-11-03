/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ivda-cru <ivda-cru@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 22:29:05 by ivda-cru          #+#    #+#             */
/*   Updated: 2022/11/03 13:07:23 by ivda-cru         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	process_map(t_tudo *tudo, char *buf, size_t bytes)
{
	int	i;

	i = 0;
	tudo->map.full_map = ft_split(buf, '\n');
	tudo->map.tmp_grid = ft_split(buf, '\n');
	free(buf);
	tudo->map.width = ft_strlen(tudo->map.full_map[0]);
	tudo->map.height = bytes / tudo->map.width;
	if (tudo->map.width < tudo->map.height)
		tudo->map.height --;
	while (i < tudo->map.height - 1)
	{
		if (ft_strlen(tudo->map.full_map[i]) != \
		ft_strlen(tudo->map.full_map[i + 1]))
			error_and_free(tudo, "Map format is invalid!\n");
		i++;
	}
}

void	import_map(char *filename, int fd, t_tudo *tudo)
{
	size_t	bytes_read;
	char	*buf;

	fd = open(filename, O_RDONLY);
	buf = (char *)malloc(sizeof(char) * BUFFER_COUNT);
	if (!buf || fd <= 0)
	{
		free(buf);
		close(fd);
		error("No such file or directory\n");
	}
	bytes_read = read(fd, buf, BUFFER_COUNT);
	check_gaps(buf, bytes_read);
	if (bytes_read <= 14)
	{
		free(buf);
		close(fd);
		error("File empty or too small to be aceptable\n");
	}
	buf[bytes_read] = '\0';
	close(fd);
	process_map(tudo, buf, bytes_read);
}

void	initialize_game(t_tudo *tudo)
{
	int	win_x;
	int	win_y;

	win_x = tudo->map.width * SPRITE_RES_X_Y;
	win_y = tudo->map.height * SPRITE_RES_X_Y + MOVE_ROW;
	tudo->mlx_init = mlx_init();
	tudo->mlx_window = mlx_new_window(tudo->mlx_init, win_x, win_y, "So_long");
	loop_grid_collectible(tudo);
	tudo->sprites = create_sprites(tudo->mlx_init);
	loop_map_grid(tudo);
}

void	initialize_variables(t_tudo *tudo)
{
	tudo->map.height = 0;
	tudo->map.width = 0;
	tudo->collectible_total = 0;
	tudo->collectible_count = 0;
	tudo->collectible_debug_count = 0;
	tudo->move_count = 0;
	tudo->exit_count = 0;
	tudo->player_count = 0;
	tudo->empty_spaces = 0;
}

int	main(int argc, char **argv)
{
	t_tudo	tudo;

	if (argc == 2)
	{
		if (!ft_strstr(argv[1], ".ber"))
			error("Map must have a .ber extension\n");
	}
	else
		error("Map file missing in argument, or too many arguments\n");
	initialize_variables(&tudo);
	import_map(argv[1], 0, &tudo);
	check_map(&tudo);
	check_valid_path(&tudo);
	initialize_game(&tudo);
	mlx_key_hook(tudo.mlx_window, &keyboard, &tudo);
	mlx_hook(tudo.mlx_window, X_EVENT_KEY_EXIT, 0, &exit_game, &tudo);
	mlx_loop(tudo.mlx_init);
	return (0);
}
