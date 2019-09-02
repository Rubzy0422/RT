/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:55:27 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 16:18:27 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	head_check(t_list *list, t_env *env)
{
	list = list->next;
	if (ft_strcmp((char *)list->content, "Scene {") != 0)
		ft_say("Scene must be spesified!", EROR, env);
	while (list)
	{
		if (!ft_strncmp((char *)list->content,"#", 1))
			list = list->next;
		obj_checker(list, env);
		if (!list->next)
			if (ft_strcmp((char *)list->content, "}") != 0)
					ft_say("Scene must end with a curly bracket!", EROR, env);
		list =list->next;
	}
}

void	obj_checker(t_list *list, t_env *env)
{
	cam_check(list, env);
	light_check(list, env);
	sphere_check(list, env);
	plane_check(list, env);
	cone_check(list, env);
	//cylinder_check(list, env);
}

void	reset_set(t_set *set)
{
	set->pos = -1;
	set->radius = -1;
	set->color = -1;
	set->reflection = -1;
	set->normal = -1;
	set->dist = -1;
}
