/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkoyamba <mkoyamba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 18:52:40 by mkoyamba          #+#    #+#             */
/*   Updated: 2022/03/17 21:08:57 by mkoyamba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

static void	exit_event(t_data *data)
{
	if (data->player.items > 0)
		return ;
	data->player.moves += 1;
	ft_printf("%i\n", data->player.moves);
	end_msg(data);
}

void	event_up(t_data *data)
{
	if (data->map[data->player.y - 1][data->player.x] == '1')
		return ;
	else if (data->map[data->player.y - 1][data->player.x] == '0' ||
		data->map[data->player.y - 1][data->player.x] == 'C')
	{
		if (data->map[data->player.y - 1][data->player.x] == 'C')
			data->player.items -= 1;
		data->map[data->player.y - 1][data->player.x] = 'P';
		data->map[data->player.y][data->player.x] = '0';
		data->player.moves += 1;
		data->player.y -= 1;
		ft_printf("%i\n", data->player.moves);
	}
	else if (data->map[data->player.y - 1][data->player.x] == 'E')
		exit_event(data);
	map_reload(data);
}

void	event_down(t_data *data)
{
	if (data->map[data->player.y + 1][data->player.x] == '1')
		return ;
	else if (data->map[data->player.y + 1][data->player.x] == '0' ||
		data->map[data->player.y + 1][data->player.x] == 'C')
	{
		if (data->map[data->player.y + 1][data->player.x] == 'C')
			data->player.items -= 1;
		data->map[data->player.y + 1][data->player.x] = 'P';
		data->map[data->player.y][data->player.x] = '0';
		data->player.moves += 1;
		data->player.y += 1;
		ft_printf("%i\n", data->player.moves);
	}
	else if (data->map[data->player.y + 1][data->player.x] == 'E')
		exit_event(data);
	map_reload(data);
}

void	event_left(t_data *data)
{
	if (data->map[data->player.y][data->player.x - 1] == '1')
		return ;
	else if (data->map[data->player.y][data->player.x - 1] == '0' ||
		data->map[data->player.y][data->player.x - 1] == 'C')
	{
		if (data->map[data->player.y][data->player.x - 1] == 'C')
			data->player.items -= 1;
		data->map[data->player.y][data->player.x - 1] = 'P';
		data->map[data->player.y][data->player.x] = '0';
		data->player.moves += 1;
		data->player.x -= 1;
		ft_printf("%i\n", data->player.moves);
	}
	else if (data->map[data->player.y][data->player.x - 1] == 'E')
		exit_event(data);
	map_reload(data);
}

void	event_right(t_data *data)
{
	if (data->map[data->player.y][data->player.x + 1] == '1')
		return ;
	else if (data->map[data->player.y][data->player.x + 1] == '0' ||
		data->map[data->player.y][data->player.x + 1] == 'C')
	{
		if (data->map[data->player.y][data->player.x + 1] == 'C')
			data->player.items -= 1;
		data->map[data->player.y][data->player.x + 1] = 'P';
		data->map[data->player.y][data->player.x] = '0';
		data->player.moves += 1;
		data->player.x += 1;
		ft_printf("%i\n", data->player.moves);
	}
	else if (data->map[data->player.y][data->player.x + 1] == 'E')
		exit_event(data);
	map_reload(data);
}
