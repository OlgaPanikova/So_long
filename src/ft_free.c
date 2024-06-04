/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 19:13:15 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/13 20:28:56 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_t_map(t_sl *map)
{
	if (map->map_input != NULL)
		free_array(map->map_input, map->map_height);
	free(map);
}

void	ft_error_map_free(t_sl *map, char *error_message)
{
	free_t_map(map);
	write(2, "Error\n", 6);
	ft_putstr_fd(error_message, 2);
	exit(1);
}

void	ft_error(char *error_message)
{
	write(2, "Error\n", 6);
	ft_putstr_fd(error_message, 2);
	exit(1);
}

void	free_array(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}

int	push_close(t_sl *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	free_t_map(vars);
	exit(0);
	return (0);
}
