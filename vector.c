/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbraum <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/15 15:50:38 by kbraum            #+#    #+#             */
/*   Updated: 2021/04/28 19:23:41 by kbraum           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_vec	vec_norm(t_vec v)
{
	t_vec		vn;
	double		len;

	len = vec_len(v);
	vn.x = v.x / len;
	vn.y = v.y / len;
	vn.z = v.z / len;
	return (vn);
}

t_vec	vec_sum(t_vec a, t_vec b)
{
	t_vec	c;

	c.x = a.x + b.x;
	c.y = a.y + b.y;
	c.z = a.z + b.z;
	return (c);
}

t_vec	vec_scale(t_vec d, double c)
{
	t_vec	cd;

	cd.x = d.x * c;
	cd.y = d.y * c;
	cd.z = d.z * c;
	return (cd);
}

double	vec_len(t_coord v)
{
	return (sqrt(v.x * v.x + v.y * v.y + v.z * v.z));
}

double	vec_dot(t_vec v1, t_vec v2)
{
	return (v1.x * v2.x + v1.y * v2.y + v1.z * v2.z);
}
