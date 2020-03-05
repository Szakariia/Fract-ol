/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:55:09 by szakaria          #+#    #+#             */
/*   Updated: 2020/02/12 16:57:38 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		key_bord(int key, t_mlx *mlx)
{
	if (key == 53)
	{
		free(mlx);
		exit(0);
	}
	else if (mlx->fractol == 3 && key == 49)
		mlx->stop = (mlx->stop) ? 0 : 1;
	else if (key == 116)
		mlx->fractol = (mlx->fractol < 3) ? mlx->fractol += 1 : 1;
	else if (key == 121)
		mlx->fractol = (mlx->fractol > 1) ? mlx->fractol -= 1 : 3;
	ft_move(mlx, key);
	if (key == 116 || key == 121)
		open_fractol(mlx);
	return (0);
}

t_mlx	*zero_mlx(t_mlx *mlx, char **argv)
{
	mlx->x_move = -2.00;
	mlx->y_move = -2.00;
	mlx->x = 0;
	mlx->y = 0;
	mlx->fractol = 0;
	if (!ft_strcmp("burningship", argv[1]))
		mlx->fractol = 1;
	if (!ft_strcmp("mandelbrot", argv[1]))
		mlx->fractol = 2;
	if (!ft_strcmp("julia", argv[1]))
		mlx->fractol = 3;
	return (mlx);
}

int		mouse_move(int x, int y, void *mlx)
{
	t_mlx *m;

	m = (t_mlx *)mlx;
	if (m->fractol != 3 || m->stop)
		return (0);
	m->x_mose = x;
	m->y_mose = y;
	mlx_clear_window(m->ptr, m->win);
	menu(mlx);
	julia(m);
	return (1);
}

int		mouse_press(int button, int x, int y, void *mlx)
{
	t_mlx *m;

	m = (t_mlx *)mlx;
	x = 0;
	y = 0;
	if (button == 4)
		m->zoom += 0.10;
	if (button == 5)
		m->zoom -= 0.10;
	if (m->fractol == 1 || m->fractol == 2 || (m->fractol && m->stop))
	{
		mlx_clear_window(m->ptr, m->win);
		menu(mlx);
	}
	if (m->fractol == 1)
		burning_ship(m);
	else if (m->fractol == 2)
		mandelbrot(m);
	else if (m->fractol == 3 && m->stop)
		julia(m);
	return (1);
}

int		main(int ac, char **argv)
{
	t_mlx	*mlx;

	if (ac != 2)
		return (ft_error(1, argv[1]));
	mlx = (t_mlx *)malloc(sizeof(t_mlx));
	mlx = zero_mlx(mlx, argv);
	if (!mlx->fractol)
	{
		free(mlx);
		return (ft_error(2, argv[1]));
	}
	mlx->stop = 0;
	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, 800, 500, "FRACTOL 1337");
	mlx->zoom = 4;
	mlx->img = mlx_new_image(mlx->ptr, 500, 500);
	mlx->data = (int *)mlx_get_data_addr(mlx->img, &mlx->i, &mlx->cc, &mlx->j);
	mlx_hook(mlx->win, 6, 0, mouse_move, mlx);
	mlx_hook(mlx->win, 4, 0, mouse_press, mlx);
	mlx_key_hook(mlx->win, key_bord, mlx);
	open_fractol(mlx);
	mlx_loop(mlx->ptr);
}
