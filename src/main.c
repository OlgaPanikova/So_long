/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:45:47 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 20:25:08 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	start_game(t_sl *vars)
{
	vars->mlx = mlx_init();
	vars->win = mlx_new_window(vars->mlx, vars->map_width * 50, \
		vars->map_height * 50, "so_long");
	paint_map (vars);
	mlx_hook(vars->win, 2, 1L << 0, key_hook, vars);
	mlx_hook(vars->win, 17, 1L << 0, push_close, vars);
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
