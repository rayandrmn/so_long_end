/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_perso.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 16:17:29 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 14:09:43 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	init_perso(t_game *game, t_checkmap *mapfile)
{
	char	*path;

	game->perso.x = 0;
	game->perso.y = 0;
	game->perso.ligne = 0;
	game->perso.colone = 0;
	game->perso.piece = 0;
	game->perso.count = 0;
	game->perso.map = mapfile->test;
	game->perso.ligne = mapfile->ligne;
	game->perso.colone = mapfile->colone;
	path = "assets/perso.xpm";
	player_pos(&game->perso);
	game->img_ptr = mlx_xpm_file_to_image(game->mlx_ptr,
			path, &game->perso.width, &game->perso.height);
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		game->img_ptr, game->perso.x, game->perso.y);
	return (0);
}

void	player_pos(t_perso *perso)
{
	int	x;
	int	y;

	x = 0;
	y = 1;
	while (y < perso->ligne)
	{
		while (x < perso->colone)
		{
			if (perso->map[y][x] == 'p')
			{
				perso->x = x * 64;
				perso->y = y * 64;
			}
			x++;
		}
		x = 0;
		y++;
	}
}

void	perso_move(t_game *game, void *img_ptr, int key)
{
	game->perso.count++;
	ft_printf("\n nombre de deplacement : %d", game->perso.count);
	mlx_clear_window(game->mlx_ptr, game->win_ptr);
	colision(game, key);
	load_all(game);
	(void)img_ptr;
	mlx_put_image_to_window(game->mlx_ptr, game->win_ptr,
		img_ptr, game->perso.x, game->perso.y);
}

int	add_index(t_game *game, int *pos)
{
	int	x;
	int	y;

	x = game->perso.x / 64 ;
	y = game->perso.y / 64;
	if (game->perso.map[y][x] == '1')
	{
		*pos = *pos + 64;
		return (0);
	}
	if (game->perso.map[y][x] == 'c')
	{
		game->perso.count++;
		game->perso.piece += 1;
		game->perso.map[y][x] = '0';
	}
	if (game->perso.map[y][x] == 'e')
	{
		if (game->perso.piece == game->mapfile->piece)
		{
			ft_printf("\nfin du jeu bravo\n");
			on_destroy(game);
		}
	}
	return (1);
}

int	remove_index(t_game *game, int *pos)
{
	int	x;
	int	y;

	x = game->perso.x / 64 ;
	y = game->perso.y / 64;
	if (game->perso.map[y][x] == '1')
	{
		*pos = *pos - 64;
		return (0);
	}
	if (game->perso.map[y][x] == 'c')
	{
		game->perso.piece += 1;
		game->perso.map[y][x] = '0';
	}
	if (game->perso.map[y][x] == 'e')
	{
		if (game->perso.piece == game->mapfile->piece)
		{
			ft_printf("\nfin du jeu bravo\n");
			on_destroy(game);
		}
	}
	return (1);
}
