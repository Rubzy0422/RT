/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:47:36 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 13:00:24 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	plane_check(t_list *list, t_env *env)
{
	t_object obj;

	reset_set(&obj.set);
	if (ft_strnstr((char *)list->content,"PLANE", 5))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			if (!ft_strncmp((char *)list->content, "\tDIST", 5))
			{
				obj.dist = get_float((char *)list->content, env, 0);
				obj.set.dist = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tNORMAL", 7))
			{
				obj.normal = ft_vec3parse(list->content, env);
				obj.set.normal = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tCOLOR", 6))
			{
				obj.color = ft_color_parse(list->content, env);
				obj.set.color = 1;
			}
			list = list->next;
		}
		obj.type = "PLANE";
		if (obj.set.dist == -1 || obj.set.normal == -1 || obj.set.color == -1)
			ft_say("Plane invalid!", EROR, env);
		add_object(ft_lstnew(&obj, sizeof(obj)), env);
	}
}

int		plane_inter(t_ray *ray, t_object *plane)
{
	float k;

	k = vec_dot(&ray->origin, &plane->normal) /
		vec_dot(&ray->dir, &plane->normal);
	return (k >= 0 && k <= 1);
}