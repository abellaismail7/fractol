/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_com.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: iait-bel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/15 11:42:43 by iait-bel          #+#    #+#             */
/*   Updated: 2022/01/15 11:42:43 by iait-bel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_COM_H
# define MLX_COM_H

enum e_keys {
	UP_ARROW = 125,
	DOWN_ARROW = 126,
	LEFT_ARROW = 123,
	RIGHT_ARROW= 124,
	N_KEY = 45,
	M_KEY = 46,
	I_KEY = 34,
	O_KEY = 31,
	C_KEY = 8,
	A_KEY = 0,
	ESC_KEY = 53,
	Q_KEY = 12,
};

enum e_mouse_keys {
	CLICK_KEY = 1,
	MOUSE_SCROLL_UP = 4,
	MOUSE_SCROLL_DOWN = 5,
};

enum e_events {
	EXPOSE_EVENT = 12,
	GRAPHICS_EXPOSE_EVENT = 13,
	MOUSE_MOTION_EVENT = 6,
	DESTROY_NOTIFY_EVENT = 17,
};

#endif
