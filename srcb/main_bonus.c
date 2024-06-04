/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:45:47 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 20:25:21 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	count_symbol(t_sl *map)
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
			else if (map->map_input[i][j] == 'V')
				map->num_enemy += 1;
			else if (map->map_input[i][j] != '\0' && map->map_input[i][j] \
			!= '0' && map->map_input[i][j] != '1')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	start_game(t_sl *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 50, \
		vars->map_height * 50, "so_long");
	paint_map (vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 0, push_close, vars);
	mlx_loop_hook(vars->mlx, animal, vars);
	mlx_loop(vars->mlx);
}

int	main(int argc, char **argv)
{
	t_sl	*game;

	if (argc != 2)
		ft_error("Invalid number of arguments\n");
	game = malloc(sizeof(t_sl));
	if (!game)
		ft_error("No memory allocated\n");
	check_name_map(argv[1]);
	open_map(argv[1], game);
	start_game(game);
	return (0);
}
