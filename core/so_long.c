/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:32:49 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 14:24:18 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"
#include "../mlx/mlx.h"

int	main(int ac, char **av)
{
	t_checkmap	mapfile;
	t_game		*game;

	game = malloc(sizeof(t_game));
	if (ac != 2)
		return (error_msg("Un seul argument valable\n"));
	if (!check_file_name(av[1]))
		return (error_msg("le nom de la map doit terminer par .ber"));
	if (!check_config_map(av[1], &mapfile))
		return (error_msg("Il y a une erreur dans la map"));
	ft_printf("les parametres sont correctes le jeu se lance...\n");
	game->mapfile = &mapfile;
	init_game(&mapfile, game);
	load_texture_map(game);
	init_perso(game, &mapfile);
	mlx_hook(game->win_ptr, KeyRelease, KeyReleaseMask, &on_keypress, game);
	mlx_hook(game->win_ptr, DestroyNotify,
		StructureNotifyMask, &on_destroy, game);
	mlx_loop(game->mlx_ptr);
	return (0);
}
