/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:58 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 19:25:13 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../mlx/mlx_int.h"
# include <stdlib.h>
# include <stdio.h>
# include <sys/stat.h>
# include <fcntl.h>

typedef struct s_map
{
	int		width;
	int		height;
	char	*file;
	char	**map;
	int		items;
}	t_map;

typedef struct s_shark
{
	void	*top_left;
	void	*top_right;
	void	*bottom_left;
	void	*bottom_right;
	void	*left;
	void	*right;
	void	*current_ptr;
	char	dir;
}	t_shark;

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
	void	*wall_ptr;
	void	*items_ptr;
	void	*blank_ptr;
	void	*exit_red_ptr;
	void	*exit_green_ptr;
	int		move;
	int		prev_move;
	int		width;
	int		height;
	t_map	*map;
	t_shark	*shark;
}	t_data;

// CHECK MAP
int		ft_is_map_valid(t_data *data);
int		ft_check_map_size(t_map *stc_map);
int		ft_check_map_content(char **stc_map);
int		ft_create_map(t_map *stc_map);
int		ft_is_map_rectangle(t_map *stc_map);

// CHECK MAP2
int		floodfill(t_map *map, char newClr);
void	filler(t_map *map, int x, int y, char new);
t_map	*ft_map_cpy(t_map *map);
int		ft_check_flood_fill(char **map);

// UTILS1
int		ft_open_file(char *file);
int		check_wall(char *str);
int		on_destroy(t_data *data);
void	free_struct(t_data *data, char *str);
void	destroy_img(t_data *data);

// UTILS2
void	free_chars(char **str);
void	print_error(char *str);
void	*xpm_to_img(t_data *data, char *file_name, int *w, int *h);
void	img_to_win(t_data *data, void *img_ptr, int i, int j);
int		create_map_loop(t_map *stc_map, char *str, int fd);

// UTILS3
int		check_map_content_loop(char **map, int *e, int *c, int *p);
void	add_wall_and_items_loop(t_data *data, int i, int x, int y);
int		map_cpy_loop(t_map *map_cpy, t_map *map);
int		check_img_ptr(t_data *data);
void	init_data(t_data *data);

// UTILS4
void	check_extension(char *str);
void	init_shark(t_shark *shark);
int		ft_check_map_size_loop(t_map *stc_map, char *str, int fd);

// HANDLE GAME ASSETS
int		init_mlx(t_data *stc_data);
int		ft_load_game_assets(t_data *stc_data);
int		key_hook(int key, t_data *data);
int		add_wall_and_items(t_data *stc_data);
void	init_shark_img(t_data *data, int width, int height);

// MOVE
void	ft_move(t_data *data, char dir);
int		find_item(char **map, int *x, int *y, char item);
void	move_printer(t_data *data);

#endif
