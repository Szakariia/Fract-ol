/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: szakaria <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/12 16:57:52 by szakaria          #+#    #+#             */
/*   Updated: 2020/02/12 17:02:51 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include "libft/libft.h"
# include <unistd.h>
# include <stdio.h>
# include <mlx.h>
# include <math.h>

typedef struct	s_eq
{
	double i;
	double r;
}				t_eq;

typedef struct	s_mlx
{
	int		i;
	int		j;
	int		cc;

	int		x;
	int		y;
	int		color;
	int		iteration;

	int		fractol;
	int		stop;

	int		x_mose;
	int		y_mose;

	double	x_move;
	double	y_move;

	double	zoom;

	void	*ptr;
	void	*win;

	void	*img;
	int		*data;

	t_eq	tmp;
	t_eq	z;
	t_eq	c;
}				t_mlx;

t_mlx			*data_image(t_mlx *m);

int				ft_error(int i, char *argv);
void			ft_move(t_mlx *mlx, int key);
void			menu(t_mlx *mlx);
void			open_fractol(t_mlx *mlx);
void			julia(t_mlx *m);
void			mandelbrot(t_mlx *m);
void			burning_ship(t_mlx *m);

#endif
