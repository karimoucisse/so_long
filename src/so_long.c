/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:19:39 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 17:46:23 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	t_data	data;

	if (ac != 2)
		print_error("Error: Argument(s) not valid");
	check_extension(av[1]);
	init_data(&data);
	data.map = malloc(sizeof(t_map));
	if (!data.map)
		free_struct(&data, "Error: Malloc");
	data.map->map = NULL;
	data.map->file = av[1];
	ft_is_map_valid(&data);
	data.shark = malloc(sizeof(t_shark));
	if (!data.shark)
		free_struct(&data, "Error: Malloc");
	init_shark(data.shark);
	init_mlx(&data);
	ft_load_game_assets(&data);
	mlx_key_hook(data.win_ptr, key_hook, &data);
	mlx_hook(data.win_ptr, DestroyNotify,
		StructureNotifyMask, on_destroy, &data);
	mlx_loop_hook(data.mlx_ptr, ft_load_game_assets, &data);
	mlx_loop(data.mlx_ptr);
	on_destroy(&data);
}
