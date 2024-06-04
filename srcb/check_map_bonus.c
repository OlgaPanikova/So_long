/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 18:24:18 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 16:06:21 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_name_map(char *av)
{
	int	len;

	len = ft_strlen(av);
	if (len <= 4)
		ft_error("Incorrect map name\n");
	else if (ft_strnstr((av + (len - 4)), ".ber", 4) != NULL)
		return ;
	else
		ft_error("Incorrect map name\n");
}

int	count_lines_map(t_sl *map)
{
	char	*tmp;
	int		count_lines;
	int		fd;

	count_lines = 0;
	fd = open(map->map_pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map_free(map, "The file was not read\n");
	while (1)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			break ;
		count_lines++;
		free(tmp);
	}
	close(fd);
	map->map_height = count_lines;
	if (check_map_size(map) == 1)
		ft_error_map_free(map, "Map size is not suitable for the monitor\n");
	return (count_lines);
}

void	read_map(t_sl *map)
{
	int		i;
	int		fd;
	char	*tmp;

	i = 0;
	map->map_input = (char **)malloc(sizeof(char *) * (map->map_height + 1));
	if (map->map_input == NULL)
		ft_error_map_free(map, "No memory allocated\n");
	fd = open(map->map_pathname, O_RDONLY);
	if (fd == -1)
		ft_error_map_free(map, "The file was not read\n");
	while (i < map->map_height)
	{
		tmp = get_next_line(fd);
		if (!tmp)
			ft_error_map_free(map, "No memory allocated\n");
		map->map_input[i] = ft_strtrim(tmp, "\n");
		free(tmp);
		i++;
	}
	close(fd);
}

void	checking_map(t_sl *map)
{
	if (check_rect(map) == 1)
		ft_error_map_free(map, "The map is not rectangular\n");
	if (check_wall(map) == 1)
		ft_error_map_free(map, "There is no wall\n");
	if (check_symbol(map) == 1)
		ft_error_map_free(map, "Invalid symbol\n");
	if (check_overlaps_map(map) == 1)
		ft_error_map_free(map, "An impassable map\n");
}

void	open_map(char *map_name, t_sl *map)
{
	map->map_input = NULL;
	map->num_coint = 0;
	map->num_exit = 0;
	map->num_pos = 0;
	map->num_enemy = 0;
	map->step = 0;
	map->end_count = 0;
	map->map_pathname = map_name;
	count_lines_map(map);
	if (map->map_height == 0)
		ft_error_map_free(map, "Empty map\n");
	read_map (map);
	checking_map (map);
	return ;
}
