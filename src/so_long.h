/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanikov <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/05 12:50:04 by opanikov          #+#    #+#             */
/*   Updated: 2024/05/12 19:18:56 by opanikov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <unistd.h>
# include <stdio.h>

# include "../Libft/libft.h"
# include "../get_next_line/get_next_line.h"
# include <mlx.h>

typedef struct s_long
{
	char			*map_pathname;
	char			**map_input;
	char			*sprite_path[10];
	int				map_height;
	int				map_width;
	int				num_exit;
	int				num_pos;
	int				num_coint;
	int				x;
	int				y;
	int				end_count;
	unsigned int	step;
	void			*mlx;
	void			*win;
	void			*sprite[10];
}					t_sl;

void	open_map(char *map_name, t_sl *map);
void	check_name_map(char *av);
void	ft_error(char *error_message);
void	checking_map(t_sl *map);
void	free_t_map(t_sl *map);
void	read_map(t_sl *map);
void	ft_error_map_free(t_sl *map, char *error_message);
void	fill(t_sl *map, char **tmp, int x, int y);
void	paint_map(t_sl *vars);
void	render_map(t_sl *vars);
void	*find_sprite(char find, t_sl *vars);
void	*file_to_image(t_sl *vars, char *sprite_path);
void	init_sprite(t_sl *vars);
void	init_sprite_path(t_sl *vars);
void	start_game(t_sl *vars);
void	game_go(t_sl *vars, int y, int x, char c);
void	game_end(t_sl *vars, int y, int x);

char	**copy_map(t_sl *map);

int		count_lines_map(t_sl *map);
int		check_rect(t_sl *map);
int		check_up_down_wall(t_sl *map);
int		check_perimeter_wall(t_sl *map);
int		check_wall(t_sl *map);
int		check_symbol(t_sl *map);
int		check_overlaps_map(t_sl *map);
int		check_exit_coin(char **tmp_map, char a);
int		key_hook(int keycode, t_sl *vars);
int		push_close(t_sl *vars);
int		check_map_size(t_sl *map);

void	free_array(char **array, int size);
void	chek_leaks(void);

#endif 