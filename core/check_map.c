/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 14:31:14 by rayderha          #+#    #+#             */
/*   Updated: 2024/08/14 16:47:53 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	check_file_name(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (!ft_strnstr((av + len - 4), ".ber", len))
		return (0);
	return (1);
}

void	init_checkmap(t_checkmap *mapfile)
{
	mapfile->map = 0;
	mapfile->temp = 0;
	mapfile->str = 0;
	mapfile->test = 0;
	mapfile->player = 0;
	mapfile->piece = 0;
	mapfile->exit = 0;
	mapfile->piece = 0;
}

void	get_map(t_checkmap *mapfile, int fd)
{
	while (1)
	{
		if (!mapfile->map)
		{
			mapfile->map = get_next_line(fd);
			if (mapfile->map == NULL)
			{
				free(mapfile->map);
				break ;
			}
		}
		else
		{
			mapfile->str = get_next_line(fd);
			if (mapfile->str == NULL)
			{
				free(mapfile->str);
				break ;
			}
			mapfile->temp = ft_strjoin(mapfile->map, mapfile->str);
			free(mapfile->map);
			mapfile->map = mapfile->temp;
			free(mapfile->str);
		}
	}
}

int	check_config_map(char *av, t_checkmap *mapfile)
{
	int			fd;

	init_checkmap(mapfile);
	fd = open(av, O_RDONLY);
	if (fd == -1)
		return (0);
	get_map(mapfile, fd);
	mapfile->test = 0;
	mapfile->test = ft_split(mapfile->map, '\n');
	if (!check_wall(mapfile))
		return (0);
	if (!check_content(mapfile))
		return (0);
	close(fd);
	return (1);
}
