/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:08:54 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 14:05:54 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	init_game(t_checkmap *mapfile, t_game *game)
{
	game->mlx_ptr = mlx_init();
	if (!game->mlx_ptr)
		return (0);
	game->win_ptr = mlx_new_window(game->mlx_ptr, (64 * mapfile->colone),
			(64 * mapfile->ligne), "so_long");
	if (!game->win_ptr)
		return (free(game->mlx_ptr), 1);
	return (1);
}

void	draw_element(t_game *game, char element, int x, int y)
{
	if (element == '1')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->mur_ptr, (x * 64), (y * 64));
	else if (element == '0' || element == 'p')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->sol_ptr, (x * 64), (y * 64));
	else if (element == 'c')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->piece_ptr, (x * 64), (y * 64));
	else if (element == 'e')
		mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
			game->exit_ptr, (x * 64), (y * 64));
}

int	load_all(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (y < game->mapfile->ligne)
	{
		while (x < game->mapfile->colone)
		{
			draw_element(game, game->mapfile->test[y][x], x, y);
			x++;
		}
		x = 0;
		y++;
	}
	return (0);
}

int	load_texture_map(t_game *game)
{
	char	*path;
	int		width;
	int		height;

	path = "assets/mur.xpm";
	game->mur_ptr = mlx_xpm_file_to_image(game->mlx_ptr, path, &width, &height);
	game->sol_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/sol.xpm", &width, &height);
	game->exit_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/sortie.xpm", &width, &height);
	game->piece_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			"assets/piece.xpm", &width, &height);
	load_all(game);
	return (0);
}

int	colision(t_game *game, int key)
{
	if (key == 1)
	{
		return (add_index(game, &game->perso.x));
	}
	if (key == 2)
	{
		return (add_index(game, &game->perso.y));
	}
	if (key == 3)
	{
		return (remove_index(game, &game->perso.y));
	}
	if (key == 4)
	{
		return (remove_index(game, &game->perso.x));
	}
	return (1);
}
