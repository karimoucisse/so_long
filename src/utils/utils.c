/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:01 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 17:59:30 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libft/libft.h"

int	ft_open_file(char *file)
{
	int	fd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
	{
		perror(file);
		return (-1);
	}
	return (fd);
}

int	check_wall(char *str)
{
	while (*str)
	{
		if (*str != '1')
			return (0);
		str++;
	}
	return (1);
}

int	on_destroy(t_data *data)
{
	if (data->mlx_ptr)
		destroy_img(data);
	if (data->shark)
		free(data->shark);
	if (data->map->map)
		free_chars(data->map->map);
	if (data->map)
		free(data->map);
	if (data->mlx_ptr && data->win_ptr)
	{
		if (data->win_ptr)
			mlx_destroy_window(data->mlx_ptr, data->win_ptr);
		mlx_destroy_display(data->mlx_ptr);
		free(data->mlx_ptr);
	}
	exit(EXIT_SUCCESS);
}

void	free_struct(t_data *data, char *str)
{
	if (data)
	{
		if (data->shark != NULL)
			free(data->shark);
		if (data->map->map != NULL)
			free_chars(data->map->map);
		if (data->map != NULL)
			free(data->map);
		if (data->mlx_ptr != NULL)
		{
			if (data->win_ptr)
				mlx_destroy_window(data->mlx_ptr, data->win_ptr);
			mlx_destroy_display(data->mlx_ptr);
			free(data->mlx_ptr);
		}
		if (str)
			print_error(str);
	}
	else
		exit(EXIT_FAILURE);
}

void	destroy_img(t_data *data)
{
	if (data->wall_ptr)
		mlx_destroy_image(data->mlx_ptr, data->wall_ptr);
	if (data->items_ptr)
		mlx_destroy_image(data->mlx_ptr, data->items_ptr);
	if (data->blank_ptr)
		mlx_destroy_image(data->mlx_ptr, data->blank_ptr);
	if (data->exit_red_ptr)
		mlx_destroy_image(data->mlx_ptr, data->exit_red_ptr);
	if (data->exit_green_ptr)
		mlx_destroy_image(data->mlx_ptr, data->exit_green_ptr);
	if (data->shark && data->shark->top_left)
		mlx_destroy_image(data->mlx_ptr, data->shark->top_left);
	if (data->shark && data->shark->top_right)
		mlx_destroy_image(data->mlx_ptr, data->shark->top_right);
	if (data->shark && data->shark->bottom_left)
		mlx_destroy_image(data->mlx_ptr, data->shark->bottom_left);
	if (data->shark && data->shark->bottom_right)
		mlx_destroy_image(data->mlx_ptr, data->shark->bottom_right);
	if (data->shark && data->shark->left)
		mlx_destroy_image(data->mlx_ptr, data->shark->left);
	if (data->shark && data->shark->right)
		mlx_destroy_image(data->mlx_ptr, data->shark->right);
}
