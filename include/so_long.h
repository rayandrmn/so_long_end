/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 19:38:33 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 14:31:11 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stddef.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../mlx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>

typedef struct s_checkmap
{
	int			ligne;
	int			colone;
	int			player;
	int			piece;
	int			exit;
	int			max;
	int			tempp;
	int			mur_width;
	int			mur_height;
	char		*map;
	char		**test;
	char		*str;
	char		*temp;
	char		*mur_ptr;
	char		*piece_ptr;
	char		*exit_ptr;
	char		*sol_ptr;
}	t_checkmap;

typedef struct s_perso
{
	void	*img_ptr;
	int		x;
	int		y;
	int		width;
	int		height;
	char	**map;
	int		ligne;
	int		colone;
	int		piece;
	int		count;
}	t_perso;

typedef struct s_game
{
	t_checkmap	*mapfile;
	void		*mlx_ptr;
	void		*win_ptr;
	void		*mur_ptr;
	void		*piece_ptr;
	void		*exit_ptr;
	void		*sol_ptr;
	void		*img_ptr;	
	int			width;
	int			height;
	t_perso		perso;
}	t_game;

typedef struct s_map
{
	char	**position;
}	t_map;

int		error_msg(char *msg);
int		check_file_name(char *av);
int		check_config_map(char *av, t_checkmap *mapfile);
int		check_wall(t_checkmap *mapfile);
int		check_content(t_checkmap *mapfile);
int		init_game(t_checkmap *mapfile, t_game *game);
int		on_destroy(t_game *game);
int		on_keypress(int keysym, t_game *game);
int		free_checkmap(t_checkmap *mapfile);
int		init_perso(t_game *game, t_checkmap *mapfile);
int		load_texture_map(t_game *game);
int		load_all(t_game *game);

void	player_pos(t_perso *perso);
void	free_all_img(t_game *game);
void	perso_move(t_game *game, void *img_ptr, int key);
void	put_perso(t_game *game);
int		colision(t_game *game, int key);
int		add_index(t_game *game, int *pos);
int		remove_index(t_game *game, int *pos);

#endif
