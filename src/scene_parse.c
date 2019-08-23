/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:07:28 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/23 07:05:44 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

t_vec3	ft_vec3parse(char *str, t_env *env)
{
	t_vec3	tmp;
	char	*sub;
	char	**split;
	unsigned int i;

	i = 0;
	sub = ft_strcsub(str, '[', ']');
	split = ft_strsplit(sub, ',');
	while(split[i])
		i++;
	if (i != 3)
		ft_say("Vector Problem!" , EROR, env);
	tmp.x = ft_atof(split[0]);
	tmp.y = ft_atof(split[1]);
	tmp.z = ft_atof(split[2]);
	ft_freearr(split);
	free(sub);
	return (tmp);
}

void	cam_check(t_list *list, t_env *env)
{
	t_cam cam;
	if (ft_strnstr((char *)list->content,"CAM", 3))
		{
			list = list->next;
			while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
			{	
				if (ft_strnstr((char *)list->content, "\tPOS", 4))
					cam.pos = ft_vec3parse(list->content, env);
				if (ft_strnstr((char *)list->content, "\tROTATION", 9))
					cam.down = ft_vec3parse(list->content, env);
				list =list->next;
			}
		}
		(void)cam;
}

void	light_check(t_list *list, t_env *env)
{	
	if (ft_strnstr((char *)list->content,"LIGHT", 5))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			ft_putstr("LIGHT:");
			ft_putendl(list->content);
			list =list->next;
		}
	}
	(void)env;
}

void	plane_check(t_list *list, t_env *env)
{
	if (ft_strnstr((char *)list->content,"PLANE", 5))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			ft_putstr("PLANE:");
			ft_putendl(list->content);
			list =list->next;
		}
	}
	(void)env;
}

void	sphere_check(t_list *list, t_env *env)
{
	if (ft_strnstr((char *)list->content,"SPHERE", 6))
	{
		list = list->next;
		while (!ft_strncmp((char *)list->content,"\t", 1) && list->next)
		{	
			ft_putstr("SPHERE:");
			ft_putendl(list->content);
			list =list->next;
		}
	}
	(void)env;
}

void	obj_checker(t_list *list, t_env *env)
{
	cam_check(list, env);
	light_check(list, env);
	plane_check(list, env);
	sphere_check(list, env);
}

void	head_check(t_list *list, t_env *env)
{
	list = list->next;
	if (ft_strcmp((char *)list->content, "Scene {") != 0)
		ft_say("Scene must be spesified!", EROR, env);
	while (list)
	{
		if (!ft_strncmp((char *)list->content,"#", 1))
			list = list->next; // skip this line
		obj_checker(list, env);
		if (!list->next)
			if (ft_strcmp((char *)list->content, "}") != 0)
					ft_say("Scene must end with a curly bracket!", EROR, env);
		list =list->next;
	}
}

void	scene_parse(int fd, t_env *env)
{
	t_list	*head;
	t_list	*tmp;
	char	*ln;

	env->scene_lines = 0;
	head = ft_lstnew(NULL, 0);
	while (get_next_line(fd, &ln) > 0)
	{
		tmp = head;
		while (tmp->next != NULL)
			tmp = tmp->next;
		tmp->next = ft_lstnew(ln, ft_strlen(ln) + 1);
		env->scene_lines++;
		free(ln);
	}
	tmp = head;
	head_check(tmp, env);
	free(head);
}
