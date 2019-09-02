/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 20:56:25 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/27 21:06:46 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	light_add(t_vec3 pos, float s, t_env *env)
{
	t_list *lights;
	t_light new_light;
	
	new_light.pos = pos;
	new_light.strength = s;

	if (env->scene.lights == NULL)
	{
		env->scene.lights = ft_lstnew(&new_light, sizeof(t_light));
		env->scene.lightcnt++;
		return ;
	}
	lights = env->scene.lights;
	while (lights->next != NULL)
		lights = lights->next;
	lights->next = ft_lstnew(&new_light, sizeof(t_light));
	env->scene.lightcnt++;
}

void	light_check(t_list *list, t_env *env)
{
	t_vec3	pos;
	int		t;
	float	s;

	t = -1;
	s = -1;
	if (ft_strnstr((char *)list->content,"LIGHT", 5))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{
			if (!ft_strncmp((char *)list->content, "\tSTREN", 6))
				s = get_float((char *)list->content, env, 1);
			else if (!ft_strncmp((char *)list->content, "\tPOINT", 6) && (t == -1))
			{
				pos = ft_vec3parse((char *)list->content, env);
				t = 1;
			}
			list = list->next;
		}
		if (s <= 0)
				ft_say("light strength not set!", EROR, env);
		light_add(pos, s, env);
	}
}