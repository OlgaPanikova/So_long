/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animal_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/13 18:21:27 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 20:11:45 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	swap_person(t_sl *vars)
{
	vars->tmp = vars->sprite[10];
	vars->sprite[10] = vars->sprite[11];
	vars->sprite[11] = vars->tmp;
	vars->tmp = vars->sprite[2];
	vars->sprite[2] = vars->sprite[14];
	vars->sprite[14] = vars->tmp;
	vars->tmp = vars->sprite[3];
	vars->sprite[3] = vars->sprite[13];
	vars->sprite[13] = vars->tmp;
	vars->tmp = vars->sprite[4];
	vars->sprite[4] = vars->sprite[15];
	vars->sprite[15] = vars->tmp;
	vars->tmp = vars->sprite[5];
	vars->sprite[5] = vars->sprite[16];
	vars->sprite[16] = vars->tmp;
	vars->tmp = vars->sprite[12];
	vars->sprite[12] = vars->sprite[17];
	vars->sprite[17] = vars->tmp;
}

int	animal(t_sl *vars)
{
	static int	i;

	if (i % 2000 == 0)
		i = 0;
	if (i % 1000 == 0)
	{
		swap_person(vars);
		render_map(vars);
	}
	i++;
	return (0);
}

void	print_step(t_sl *vars)
{
	vars->step_str = ft_itoa(vars->step);
	mlx_string_put(vars->mlx, vars->win, 10, 25, 0xffffffff, "STEP ");
	mlx_string_put(vars->mlx, vars->win, 50, 25, 0xffffffff, vars->step_str);
	free(vars->step_str);
}
