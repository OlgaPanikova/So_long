/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_end_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 16:09:32 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 20:13:14 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_end(t_sl *vars, int y, int x)
{
	vars->end_count = 1;
	vars->map_input[vars->y][vars->x] = '0';
	vars->map_input[y][x] = 'W';
	vars->y = y;
	vars->x = x;
	vars->step += 1;
	print_step(vars);
	vars->sprite[18] = vars->sprite[20];
	render_map(vars);
	mlx_loop(vars->mlx);
}

void	game_loss(t_sl *vars, int y, int x)
{
	vars->end_count = 1;
	vars->map_input[vars->y][vars->x] = '0';
	vars->map_input[y][x] = 'X';
	vars->y = y;
	vars->x = x;
	vars->step += 1;
	print_step(vars);
	vars->sprite[18] = vars->sprite[19];
	render_map(vars);
	mlx_loop(vars->mlx);
}
