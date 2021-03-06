/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   triangle.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/22 18:37:50 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/28 19:28:06 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_cross(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.z * b.y - a.y * b.z;
	c.y = a.x * b.z - a.z * b.x;
	c.z = a.y * b.x - a.x * b.y;
	return (c);
}

void	triangle_init(t_figure *fig, char *line)
{
	t_triangle	*tr;
	char		*s;

	fig->id = ID_TR;
	tr = (t_triangle *)malloc(sizeof(t_triangle));
	if (tr == 0)
		minirt_exit(line);
	s = line + 2;
	fig->param = tr;
	if (read_coord(&s, &tr->p0) == 0
		|| read_coord(&s, &tr->p1) == 0
		|| read_coord(&s, &tr->p2) == 0
		|| read_color(&s, &fig->color) == 0)
		minirt_exit(line);
	tr->n = vec_cross(vec_init(tr->p0, tr->p1), vec_init(tr->p0, tr->p2));
	if (vec_len(tr->n) == 0)
		minirt_exit(line);
}

double	triangle_getdist(t_triangle *tr, t_coord o, t_vec od)
{
	double	d;
	double	u;
	double	v;
	t_vec	tvec;
	t_vec	qvec;

	d = -vec_dot(od, tr->n);
	if (fabs(d) < T_MIN)
		return (INF);
	tvec = vec_init(tr->p0, o);
	u = vec_dot(tvec, vec_cross(od, vec_init(tr->p0, tr->p2))) / d;
	if (u < -T_MIN || u > 1 + T_MIN)
		return (INF);
	qvec = vec_cross(tvec, vec_init(tr->p0, tr->p1));
	v = vec_dot(od, qvec) / d;
	if (v < -T_MIN || u + v > 1 + T_MIN)
		return (INF);
	return (vec_dot(vec_init(tr->p0, tr->p2), qvec) / d);
}

t_vec	triangle_normal(t_triangle *tr, t_coord o, t_coord p)
{
	if (vec_dot(tr->n, vec_init(o, p)) >= T_MIN)
		return (vec_scale(tr->n, -1));
	return (tr->n);
}
