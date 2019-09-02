/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cam.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:56:55 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 08:30:35 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	cam_check(t_list *list, t_env *env)
{
	if (!ft_strncmp((char *)list->content,"CAM", 3))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			if (!ft_strncmp((char *)list->content, "\tPOS", 4))
				env->scene.cam.origin = ft_vec3parse(list->content, env);
			if (!ft_strncmp((char *)list->content, "\tDIR", 4))
				env->scene.cam.dir = ft_vec3parse(list->content, env);
			list =list->next;
		}
	}
}