/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_handler.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: madias-m <madias-m@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/28 20:52:27 by madias-m          #+#    #+#             */
/*   Updated: 2024/03/28 20:56:33 by madias-m         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	on_key_press(int key, t_canvas *cvs)
{
	if (key == ESC)
		quit_game(cvs);
	else
		move_player(key, cvs);
	return (0);
}
