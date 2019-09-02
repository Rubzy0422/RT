/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 07:42:57 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 09:36:50 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

t_vec3 vec_sub(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 result;

	result = (t_vec3){v1->x - v2->x, v1->y - v2->y, v1->z - v2->z};
	return (result);
}

float vec_dot(t_vec3 *v1, t_vec3 *v2)
{
	return (v1->x * v2->x + v1->y * v2->y + v1->z * v2->z);
}

t_vec3	vec_scale(float c, t_vec3 *v)
{
	t_vec3 result;

	result = (t_vec3){v->x * c, v->y * c, v->z * c };
	return (result);
}

t_vec3 vec_add(t_vec3 *v1, t_vec3 *v2)
{
	t_vec3 result;

	result = (t_vec3){v1->x + v2->x, v1->y + v2->y, v1->z + v2->z };
	return (result);
}

void	vec_norm(t_vec3 *v)
{
	double len = sqrt((v->x * v->x) + (v->y * v->y) + (v->z * v->z));
	if (len < 1)
	printf("%lf, %lf, %lf : %lf\n", v->x, v->y, v->z, len);
	v->x = v->x / len;
	v->y = v->y / len;
	v->z = v->z / len;
}
