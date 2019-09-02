/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 19:07:28 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 08:52:02 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

float	get_float(char *str, t_env *env, int boolean)
{
	float	tmp;
	char	*sub;

	sub = ft_strcsub(str, '[', ']');
	tmp = ft_atof(sub);
	if (boolean && (tmp  < 0 && tmp > 1))
		ft_say("Invalid NUMBER ENTERED!", EROR, env);
	free(sub);
	return (fabs(tmp));
}

int	ft_color_parse(char *str, t_env *env)
{
	t_color	tmp;
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
	tmp.red = ft_atof(split[0]);
	tmp.green = ft_atof(split[1]);
	tmp.blue = ft_atof(split[2]);
	ft_freearr(split);
	free(sub);
	tmp.red = (tmp.red >= 0 && tmp.red <= 255) ? tmp.red: 0;
	tmp.green = (tmp.green >= 0 && tmp.green <= 255) ? tmp.green: 0;
	tmp.blue = (tmp.blue >= 0 && tmp.blue <= 255) ? tmp.blue: 0;
	return (rgb_to_hex(tmp));
}

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

void		add_object(t_list *new_object, t_env *env)
{
	t_list	*objects;

	if (env->scene.objects == NULL)
	{
		env->scene.objects = new_object;
		env->scene.objcnt++;
		return ;
	}
	objects = env->scene.objects;
	while (objects->next != NULL)
		objects = objects->next;
	objects->next = new_object;
	env->scene.objcnt++;
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
	ft_lstdel(&head, ft_del);
	if (env->scene.lightcnt == 0)
		ft_say("No light source found!", EROR, env);
}
