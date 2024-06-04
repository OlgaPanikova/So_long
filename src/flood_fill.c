/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/07 20:48:50 by lelichik          #+#    #+#             */
/*   Updated: 2024/05/13 16:04:04 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(t_sl *map, char **tmp, int x, int y)
{
	if (!(tmp[y][x] == 'C' || tmp[y][x] == '0'
	|| tmp[y][x] == 'E' || tmp[y][x] == 'P'))
		return ;
	tmp[y][x] += 3;
	if (tmp[y][x] == 'H')
		return ;
	fill(map, tmp, x - 1, y);
	fill(map, tmp, x, y - 1);
	fill(map, tmp, x, y + 1);
	fill(map, tmp, x + 1, y);
}

int	check_overlaps_map(t_sl *map)
{
	char	**tmp;

	tmp = copy_map(map);
	map->y = 0;
	while (map->map_input[map->y])
	{
		map->x = 0;
		while (map->map_input[map->y][map->x])
		{
			if (map->map_input[map->y][map->x] == 'P')
				break ;
			map->x += 1;
		}
		if (map->map_input[map->y][map->x] == 'P')
			break ;
		map->y += 1;
	}
	fill(map, tmp, map->x, map->y);
	if ((check_exit_coin(tmp, 'C') == 1) || (check_exit_coin(tmp, 'E') == 1))
	{
		free_array(tmp, map->map_height);
		return (1);
	}
	free_array(tmp, map->map_height);
	return (0);
}

int	check_exit_coin(char **tmp_map, char a)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (tmp_map[i])
	{
		while (tmp_map[i][j])
		{
			if (tmp_map[i][j] == a)
				return (1);
			j++;
		}
		j = 0;
		i++;
	}
	return (0);
}

char	**copy_map(t_sl *map)
{
	char	**tmp_map;
	int		i;
	int		len;

	i = 0;
	tmp_map = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (!tmp_map)
		ft_error_map_free(map, "No memory allocated\n");
	while (i < map->map_height)
	{
		len = ft_strlen(map->map_input[i]);
		tmp_map[i] = (char *)malloc(sizeof(char) * (len + 1));
		if (!tmp_map[i])
		{
			free(tmp_map);
			ft_error_map_free(map, "No memory allocated\n");
		}
		ft_strlcpy(tmp_map[i], map->map_input[i], len + 1);
		i++;
	}
	tmp_map[map->map_height] = NULL;
	return (tmp_map);
}

int	check_map_size(t_sl *map)
{
	if (map->map_height > 22)
		return (1);
	else if (map->map_width > 41)
		return (1);
	return (0);
}
