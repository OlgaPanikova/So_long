/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/06 15:15:35 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 16:04:01 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_rect(t_sl *map)
{
	int	i;

	i = 1;
	while (i < map->map_height)
	{
		if (ft_strlen(map->map_input[i]) != ft_strlen(map->map_input[0]))
			return (1);
		i++;
	}
	map->map_width = ft_strlen(map->map_input[0]);
	if (check_map_size(map) == 1)
		ft_error_map_free(map, "Map size is not suitable for the monitor\n");
	return (0);
}

int	check_up_down_wall(t_sl *map)
{
	int	j;

	j = 0;
	while (map->map_input[0][j] != '\0')
	{
		if (map->map_input[0][j] == '1')
			j++;
		else if (map->map_input[0][j] != '1')
			return (1);
	}
	j = 0;
	while (map->map_input[map->map_height - 1][j] != '\0')
	{
		if (map->map_input[map->map_height - 1][j] == '1')
			j++;
		else if (map->map_input[map->map_height - 1][j] != '1')
			return (1);
	}
	return (0);
}

int	check_perimeter_wall(t_sl *map)
{
	int	i;
	int	j;

	i = 1;
	while (i < map->map_height - 1)
	{
		j = 0;
		if (map->map_input[i][j] != '1')
			return (1);
		else
		{
			while (map->map_input[i][j])
				j++;
		}
		if (map->map_input[i][j - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

int	check_wall(t_sl *map)
{
	if (check_up_down_wall(map) == 1)
		return (1);
	if (check_perimeter_wall(map) == 1)
		return (1);
	return (0);
}

int	check_symbol(t_sl *map)
{
	int	i;
	int	j;

	i = 0;
	while (i < map->map_height)
	{
		j = 0;
		while (map->map_input[i][j] != '\0')
		{
			if (map->map_input[i][j] == 'E')
				map->num_exit += 1;
			else if (map->map_input[i][j] == 'C')
				map->num_coint += 1;
			else if (map->map_input[i][j] == 'P')
				map->num_pos += 1;
			else if (map->map_input[i][j] != '\0' && map->map_input[i][j] \
			!= '0' && map->map_input[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	if (map->num_exit != 1 || map->num_pos != 1 || map->num_coint < 1)
		return (1);
	return (0);
}
