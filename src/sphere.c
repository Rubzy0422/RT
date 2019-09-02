/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:45:59 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 12:08:55 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	sphere_check(t_list *list, t_env *env)
{
	t_object obj;
	reset_set(&obj.set);
	if (ft_strnstr((char *)list->content,"SPHERE", 6))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			if (!ft_strncmp((char *)list->content, "\tPOS", 4))
			{
				obj.pos = ft_vec3parse((char *)list->content, env);
				obj.set.pos = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tRADIUS", 7))
			{
				obj.radius = get_float(list->content, env, 0);
				obj.set.radius = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tCOLOR", 6))
			{
				obj.color = ft_color_parse(list->content, env);
				obj.set.color = 1;
			}
			list = list->next;
		}
		obj.type = "SPHERE";
		if (obj.set.pos == -1 || obj.set.radius == -1 || obj.set.color == -1)
			ft_say("SPHERE invalid!", EROR, env);
		add_object(ft_lstnew(&obj, sizeof(obj)), env);
	}
}

int sphere_inter(t_ray *ray, t_object *sphere)
{	
	float A = vec_dot(&ray->dir, &ray->dir); 
	t_vec3 dist = vec_sub(&ray->origin, &sphere->pos);
	float B = 2 * vec_dot(&ray->dir, &dist);
	float C = vec_dot(&dist, &dist) - (sphere->radius * sphere->radius);
	float discr = B * B - 4 * A * C;
	if(discr < 0)
		return 0;
	else
		return 1;
}