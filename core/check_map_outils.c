/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_outils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rayderha <rayderha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/14 16:42:56 by rayderha          #+#    #+#             */
/*   Updated: 2024/11/18 13:12:38 by rayderha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"
#include "../libft/libft.h"

int	check_first(t_checkmap *mapfile)
{
	int	i;

	i = 0;
	while (mapfile->test[0][i])
	{
		if (mapfile->test[0][i] != '1' && mapfile->test[0][i] != '\n')
		{
			return (0);
		}
		i++;
	}
	return (1);
}

int	check_last(t_checkmap *mapfile)
{
	int	i;

	i = 0;
	while (mapfile->test[mapfile->max][i])
	{
		if (mapfile->test[mapfile->max][i] != '1' &&
mapfile->test[mapfile->max][i] != '\n')
		{
			return (0);
		}
		i++;
	}
	if (mapfile->colone != i)
		return (0);
	return (1);
}

int	check_mid(t_checkmap *mapfile)
{
	int	i;
	int	j;

	i = 0;
	j = 1;
	while (j < mapfile->max)
	{
		if (mapfile->test[j][0] != '1' ||
mapfile->test[j][mapfile->colone - 1] != '1')
		{
			return (0);
		}
		i = 0;
		while (mapfile->test[j][i])
		{
			i++;
		}
		if (i != mapfile->colone)
		{
			return (0);
		}
		j++;
	}
	return (1);
}

int	check_content(t_checkmap *mapfile)
{
	int	i;

	i = 0;
	while (mapfile->map[i])
	{
		if (mapfile->map[i] == 'c')
			mapfile->piece += 1;
		else if (mapfile->map[i] == 'p')
			mapfile->player += 1;
		else if (mapfile->map[i] == 'e')
			mapfile->exit = 1;
		else if (mapfile->map[i] != '1' && mapfile->map[i] != '0'
			&& mapfile->map[i] != '\n')
			return (0);
		i++;
	}
	if (mapfile->player > 1)
		return (0);
	if (mapfile->piece && mapfile->player && mapfile->exit)
		return (1);
	return (0);
}

int	check_wall(t_checkmap *mapfile)
{
	mapfile->max = 0;
	mapfile->ligne = 0;
	while (mapfile->test[mapfile->ligne])
		mapfile->ligne++;
	mapfile->max = mapfile->ligne - 1;
	mapfile->colone = ft_strlen(mapfile->test[0]);
	if (!check_first(mapfile) || !check_mid(mapfile) || !check_last(mapfile))
	{
		return (0);
	}
	return (1);
}
