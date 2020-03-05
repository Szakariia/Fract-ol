/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   julia.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:50:25 by szakaria          #+#    #+#             */
/*   Updated: 2020/02/12 16:50:59 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

t_mlx		*data_image(t_mlx *m)
{
	if (m->iteration == 100)
		m->color = 0;
	else
		m->color = 0xfff000 * m->iteration;
	m->data[m->y * 500 + m->x] = m->color;
	return (m);
}

void		julia(t_mlx *m)
{
	m->y = 0;
	while (m->y < 500)
	{
		m->x = 0;
		while (m->x < 500)
		{
			m->iteration = 1;
			m->c.i = -2 + m->y_mose / 500.0;
			m->c.r = -2 + m->x_mose / 500.0;
			m->z.r = m->x_move + m->x / 500.0 * 4 * m->zoom;
			m->z.i = m->y_move + m->y / 500.0 * 4 * m->zoom;
			m->tmp = m->z;
			while (m->z.r * m->z.r + m->z.i * m->z.i < 4 && m->iteration < 100)
			{
				m->tmp.r = m->z.r * m->z.r - m->z.i * m->z.i + m->c.r;
				m->tmp.i = 2 * m->z.r * m->z.i + m->c.i;
				m->z = m->tmp;
				m->iteration++;
			}
			m = data_image(m);
			m->x++;
		}
		m->y++;
	}
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}
