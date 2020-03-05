/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   menu_error.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:51:11 by szakaria          #+#    #+#             */
/*   Updated: 2020/02/12 16:55:00 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void		ft_move(t_mlx *mlx, int key)
{
	if (key == 124)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->x_move += 0.10;
		open_fractol(mlx);
	}
	else if (key == 123)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->x_move -= 0.10;
		open_fractol(mlx);
	}
	else if (key == 126)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->y_move += 0.10;
		open_fractol(mlx);
	}
	else if (key == 125)
	{
		mlx_clear_window(mlx->ptr, mlx->win);
		mlx->y_move -= 0.10;
		open_fractol(mlx);
	}
}

int			ft_error(int i, char *argv)
{
	ft_putstr(" ⛔️ \x1b[31m \x1b[1m ");
	if (i == 1)
	{
		ft_putendl("Usage : <fractol>");
		ft_putendl("\x1b[92m1 : burningship");
		ft_putendl("2 : mandelbrot");
		ft_putendl("3 : julia");
		return (0);
	}
	else if (i == 2)
	{
		ft_putstr(argv);
		ft_putendl(" : is not fractal");
		return (0);
	}
	return (0);
}

void		menu(t_mlx *mlx)
{
	mlx_string_put(mlx->ptr, mlx->win, 560, 20, 0xFFFEB3B,
			" ___   ___ ___ ___ ");
	mlx_string_put(mlx->ptr, mlx->win, 560, 40, 0xFFFEB3B,
			"|_  | |_  |_  |_  |");
	mlx_string_put(mlx->ptr, mlx->win, 560, 60, 0xFFFEB3B,
			" _| |_|_  |_  | | |");
	mlx_string_put(mlx->ptr, mlx->win, 560, 80, 0xFFFEB3B,
			"|_____|___|___| |_|");
	mlx_string_put(mlx->ptr, mlx->win, 650, 160, 0xFFFEB3B, "   Page [^]");
	mlx_string_put(mlx->ptr, mlx->win, 650, 180, 0xFFFEB3B, "   Page [v]");
	mlx_string_put(mlx->ptr, mlx->win, 520, 170, 0xFFFEB3B, "Swap Fractol > ");
	mlx_string_put(mlx->ptr, mlx->win, 690, 250, 0xFFFEB3B, "[SPACE]");
	mlx_string_put(mlx->ptr, mlx->win, 520, 250, 0xFFFEB3B, "STOP Julia   > ");
	mlx_string_put(mlx->ptr, mlx->win, 690, 320, 0xFFFEB3B, "[MOUSE]");
	mlx_string_put(mlx->ptr, mlx->win, 520, 320, 0xFFFEB3B, "ZOOM Fractol > ");
	mlx_string_put(mlx->ptr, mlx->win, 650, 450, 0xFFFEB3B, "By: szakaria");
}

void		open_fractol(t_mlx *mlx)
{
	mlx_clear_window(mlx->ptr, mlx->win);
	menu(mlx);
	if (mlx->fractol == 1)
		burning_ship(mlx);
	if (mlx->fractol == 2)
		mandelbrot(mlx);
	if (mlx->fractol == 3)
		julia(mlx);
}
