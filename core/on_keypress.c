/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   on_keypress.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/16 16:34:26 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/16 16:34:31 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	on_keypress(int keysym, t_game *game)
{
	if (keysym == 65307)
		on_destroy(game);
	if (keysym == 65361)
	{
		game->perso.x -= 64;
		perso_move(game, game->img_ptr, 1);
	}
	if (keysym == 65362)
	{
		game->perso.y -= 64;
		perso_move(game, game->img_ptr, 2);
	}
	if (keysym == 65364)
	{
		game->perso.y += 64;
		perso_move(game, game->img_ptr, 3);
	}
	if (keysym == 65363)
	{
		game->perso.x += 64;
		perso_move(game, game->img_ptr, 4);
	}
	return (0);
}

int	free_checkmap(t_checkmap *mapfile)
{
	int	i;

	i = 0;
	while (i <= 6)
	{
		free(mapfile->test[i]);
		i++;
	}
	free(mapfile->test);
	free(mapfile->map);
	return (0);
}
