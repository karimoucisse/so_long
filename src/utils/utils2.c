/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcisse <kcisse@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/09 16:20:05 by kcisse            #+#    #+#             */
/*   Updated: 2024/10/12 15:17:41 by kcisse           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../so_long.h"
#include "../../libft/libft.h"
#include "../../gnl/get_next_line.h"

void	print_error(char *str)
{
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
	exit(EXIT_FAILURE);
}

void	free_chars(char **str)
{
	int	i;

	if (!(*str) || !str)
		return ;
	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	*xpm_to_img(t_data *data, char *file_name, int *w, int *h)
{
	void	*ptr;

	ptr = mlx_xpm_file_to_image(data->mlx_ptr, file_name, w, h);
	if (ptr == NULL)
		return (0);
	return (ptr);
}

void	img_to_win(t_data *data, void *img_ptr, int j, int i)
{
	mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
		img_ptr, data->width * j, data->height * i);
}

int	create_map_loop(t_map *stc_map, char *str, int fd)
{
	int	i;

	i = 1;
	while (str)
	{
		free(str);
		str = get_next_line(fd, 0);
		if (str == NULL)
			break ;
		stc_map->map[i] = ft_substr(str, 0, stc_map->width);
		if (!(stc_map->map[i]))
		{
			get_next_line(fd, 1);
			return (close(fd), free(str), 0);
		}
		i++;
	}
	stc_map->map[i] = 0;
	close(fd);
	return (1);
}
