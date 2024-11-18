/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:30:28 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 14:10:31 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	on_destroy(t_game *game)
{
	free_all_img(game);
	free_checkmap(game->mapfile);
	mlx_destroy_window(game->mlx_ptr, game->win_ptr);
	mlx_destroy_display(game->mlx_ptr);
	free (game->mlx_ptr);
	free(game);
	exit(0);
	return (0);
}

void	free_all_img(t_game *game)
{
	mlx_destroy_image(game->mlx_ptr, game->mur_ptr);
	mlx_destroy_image(game->mlx_ptr, game->img_ptr);
	mlx_destroy_image(game->mlx_ptr, game->piece_ptr);
	mlx_destroy_image(game->mlx_ptr, game->exit_ptr);
	mlx_destroy_image(game->mlx_ptr, game->sol_ptr);
}
