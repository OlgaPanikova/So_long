/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:16:00 by lelichik          #+#    #+#             */
/*   Updated: 2024/05/13 20:14:07 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	*file_to_image(t_sl *vars, char *sprite_path)
{
	int		img_w;
	int		img_h;
	void	*img;

	img = mlx_xpm_file_to_image(vars->mlx, sprite_path, &img_w, &img_h);
	if (!img)
		ft_error_map_free(vars, "Image selection failed");
	return (img);
}

void	init_sprite(t_sl *vars)
{
	vars->sprite[0] = file_to_image(vars, vars->sprite_path[0]);
	vars->sprite[1] = file_to_image(vars, vars->sprite_path[1]);
	vars->sprite[2] = file_to_image(vars, vars->sprite_path[2]);
	vars->sprite[3] = file_to_image(vars, vars->sprite_path[3]);
	vars->sprite[4] = file_to_image(vars, vars->sprite_path[4]);
	vars->sprite[5] = file_to_image(vars, vars->sprite_path[5]);
	vars->sprite[6] = file_to_image(vars, vars->sprite_path[6]);
	vars->sprite[7] = file_to_image(vars, vars->sprite_path[7]);
	vars->sprite[8] = file_to_image(vars, vars->sprite_path[8]);
	vars->sprite[9] = file_to_image(vars, vars->sprite_path[9]);
	vars->sprite[10] = file_to_image(vars, vars->sprite_path[10]);
	vars->sprite[11] = file_to_image(vars, vars->sprite_path[11]);
	vars->sprite[12] = file_to_image(vars, vars->sprite_path[12]);
	vars->sprite[13] = file_to_image(vars, vars->sprite_path[13]);
	vars->sprite[14] = file_to_image(vars, vars->sprite_path[14]);
	vars->sprite[15] = file_to_image(vars, vars->sprite_path[15]);
	vars->sprite[16] = file_to_image(vars, vars->sprite_path[16]);
	vars->sprite[17] = file_to_image(vars, vars->sprite_path[17]);
	vars->sprite[18] = file_to_image(vars, vars->sprite_path[18]);
	vars->sprite[19] = file_to_image(vars, vars->sprite_path[19]);
	vars->sprite[20] = file_to_image(vars, vars->sprite_path[20]);
}

void	init_sprite_path(t_sl *vars)
{
	vars->sprite_path[0] = "./sprites_so_long/field2.xpm";
	vars->sprite_path[1] = "./sprites_so_long/collect.xpm";
	vars->sprite_path[2] = "./sprites_so_long/p2left.xpm";
	vars->sprite_path[3] = "./sprites_so_long/p2right.xpm";
	vars->sprite_path[4] = "./sprites_so_long/p2up.xpm";
	vars->sprite_path[5] = "./sprites_so_long/p2down.xpm";
	vars->sprite_path[6] = "./sprites_so_long/pwall2.xpm";
	vars->sprite_path[7] = "./sprites_so_long/exitmsp2.xpm";
	vars->sprite_path[8] = "./sprites_so_long/exitmsp2active.xpm";
	vars->sprite_path[9] = "./sprites_so_long/exitendgame.xpm";
	vars->sprite_path[10] = "./sprites_so_long/enemy.xpm";
	vars->sprite_path[11] = "./sprites_so_long/enemy2.xpm";
	vars->sprite_path[12] = "./sprites_so_long/enemyend.xpm";
	vars->sprite_path[13] = "./sprites_so_long/p1left.xpm";
	vars->sprite_path[14] = "./sprites_so_long/p1right.xpm";
	vars->sprite_path[15] = "./sprites_so_long/p1up.xpm";
	vars->sprite_path[16] = "./sprites_so_long/p1down.xpm";
	vars->sprite_path[17] = "./sprites_so_long/enemyend2.xpm";
	vars->sprite_path[18] = "./sprites_so_long/table.xpm";
	vars->sprite_path[19] = "./sprites_so_long/tableend.xpm";
	vars->sprite_path[20] = "./sprites_so_long/tablewin.xpm";
}

void	*find_sprite_bonus(char find, t_sl *vars)
{
	if (find == 'V')
		return (vars->sprite[10]);
	else if (find == 'X')
		return (vars->sprite[12]);
	else
		return (NULL);
}

void	*find_sprite(char find, t_sl *vars)
{
	if (find == '1')
		return (vars->sprite[6]);
	else if (find == '0')
		return (vars->sprite[0]);
	else if (find == 'P')
		return (vars->sprite[2]);
	else if (find == 'U')
		return (vars->sprite[4]);
	else if (find == 'D')
		return (vars->sprite[5]);
	else if (find == 'L')
		return (vars->sprite[3]);
	else if (find == 'C')
		return (vars->sprite[1]);
	else if (find == 'E' && vars->num_coint > 0)
		return (vars->sprite[7]);
	else if (find == 'E' && vars->num_coint == 0)
		return (vars->sprite[8]);
	else if (find == 'W')
		return (vars->sprite[9]);
	else if (find == 'V' || find == 'X')
		return (find_sprite_bonus(find, vars));
	else
		return (NULL);
}
