/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   painting_map_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/10 20:25:46 by lelichik          #+#    #+#             */
/*   Updated: 2024/05/13 20:13:43 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	game_go(t_sl *vars, int y, int x, char c)
{
	while (1)
	{
		if (vars->map_input[y][x] == '1')
			return ;
		if (vars->map_input[y][x] == '0')
			break ;
		if (vars->map_input[y][x] == 'C')
		{
			vars->num_coint -= 1;
			break ;
		}
		if (vars->map_input[y][x] == 'V')
			game_loss(vars, y, x);
		if (vars->map_input[y][x] == 'E' && vars->num_coint == 0)
			game_end(vars, y, x);
		else
			return ;
	}
	vars->map_input[vars->y][vars->x] = '0';
	vars->map_input[y][x] = c;
	vars->y = y;
	vars->x = x;
	vars->step += 1;
	render_map(vars);
}

int	key_hook(int keycode, t_sl *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		free_t_map(vars);
		exit(0);
	}
	if (vars->end_count > 0)
		return (0);
	if (keycode == 13 || keycode == 126)
		game_go(vars, vars->y - 1, vars->x, 'U');
	if (keycode == 1 || keycode == 125)
		game_go(vars, vars->y + 1, vars->x, 'D');
	if (keycode == 0 || keycode == 123)
		game_go(vars, vars->y, vars->x - 1, 'L');
	if (keycode == 2 || keycode == 124)
		game_go(vars, vars->y, vars->x + 1, 'P');
	return (0);
}

void	render_map(t_sl *vars)
{
	int	i;
	int	j;

	i = 0;
	while (i < vars->map_height)
	{
		j = 0;
		while (j < vars->map_width)
		{
			mlx_put_image_to_window(vars->mlx, vars->win, \
			find_sprite(vars->map_input[i][j], vars), j * 50, i * 50);
			j++;
		}
		i++;
	}
	mlx_put_image_to_window(vars->mlx, vars->win, vars->sprite[18], 0, 0);
	print_step(vars);
}

void	paint_map(t_sl *vars)
{
	init_sprite_path(vars);
	init_sprite(vars);
	render_map(vars);
}
