/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zael-mab <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 02:01:43 by zael-mab          #+#    #+#             */
/*   Updated: 2019/12/08 23:35:55 by szakaria         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strlen(const char *str)
{
	size_t	j;

	j = 0;
	if (str[0])
		while (str[j])
			j++;
	return (j);
}
