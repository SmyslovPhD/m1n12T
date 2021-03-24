/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/23 15:24:48 by kbraum            #+#    #+#             */
/*   Updated: 2021/03/24 21:17:02 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int			read_coord(char **line, t_coord *dot)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (!ft_isdigit(**line) && !ft_strchr("-.", **line))
		return (0);
	dot->x = ft_atof(*line);
	while (ft_isdigit(**line) || ft_strchr("-.", **line))
		(*line)++;
	if (**line != ',')
		return (0);
	dot->y = ft_atof(++(*line));
	while (ft_isdigit(**line) || ft_strchr("-.", **line))
		(*line)++;
	if (**line != ',')
		return (0);
	dot->z = ft_atof(++(*line));
	while (ft_isdigit(**line) || ft_strchr("-.", **line))
		(*line)++;
	return (1);
}

int			read_vector(char **line, t_vector *v)
{
	double		len;

	if (read_coord(line, v) == 0)
		return (0);
	len = vector_len(*v);
	if (len > 1.004 || len < .995)
		ft_printf("Error: vector sells, but who's buying?\n");
	*v = vector_normalize(*v);
	return (1);
}

int			read_color(char **line, int *color)
{
	int		chanel[3];
	int		i;

	while (**line == '\t' || **line == ' ')
		(*line)++;
	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(**line))
			return (0);
		chanel[i] = ft_atoi(*line);
		while (ft_isdigit(**line))
			(*line)++;
		if (i++ < 3 && **line == ',')
			(*line)++;
	}
	while (**line == '\t' || **line == ' ')
		(*line)++;
	if (**line != '\0')
		return (0);
	*color = trgb_init(0, chanel[0], chanel[1], chanel[2]);
	return (1);
}

int			read_double(char **line, double *j)
{
	while (**line == ' ' || **line == '\t')
		(*line)++;
	if (!(ft_isdigit(**line) || **line == '.'))
		return (0);
	*j = ft_atof(*line);
	while (ft_isdigit(**line) || **line == '.')
		(*line)++;
	return (1);
}
