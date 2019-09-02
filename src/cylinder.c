/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/28 12:08:14 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 12:47:29 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	cylinder_check(t_list *list, t_env *env)
{
	t_object obj;
	reset_set(&obj.set);
	if (ft_strnstr((char *)list->content,"CYLINDER", 4))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			if (!ft_strncmp((char *)list->content, "\tPOINT", 6))
			{
				obj.pos = ft_vec3parse((char *)list->content, env);
				obj.set.pos = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tANGLE", 6))
			{
				obj.angle = get_float(list->content, env, 0);
				obj.set.angle = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tDIR", 4))
			{
				obj.direction = ft_vec3parse(list->content, env);
				obj.set.direction = 1;
			}
			if (!ft_strncmp((char *)list->content, "\tCOLOR", 4))
			{
				obj.color = ft_color_parse(list->content, env);
				obj.set.color = 1;
			}
			list = list->next;
		}
		obj.type = "CONE";
		if (obj.set.pos == -1 || obj.set.angle == -1 || obj.set.direction == -1 || obj.set.color == -1)
			ft_say("CONE invalid!", EROR, env);
		add_object(ft_lstnew(&obj, sizeof(obj)), env);
	}
}

int cylinder_inter(t_ray *ray, t_object *sphere)
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