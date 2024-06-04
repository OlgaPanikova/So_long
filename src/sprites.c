/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 16:16:00 by lelichik          #+#    #+#             */
/*   Updated: 2024/05/13 16:04:12 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	else
		return (NULL);
}
