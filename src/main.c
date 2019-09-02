/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:12 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/09/02 07:12:32 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>
#include <stdio.h>

int	check_intersection(t_ray ray, t_list *object_list)
{
	t_object	*tmp_obj;

	while (object_list)
	{
		tmp_obj = (t_object *)object_list->content;
		if (!strncmp(tmp_obj->type,"SPHERE", 6))
			if (sphere_inter(&ray, tmp_obj))
					return (tmp_obj->color);
		if (!strncmp(tmp_obj->type,"PLANE", 6))
			if (plane_inter(&ray, tmp_obj))
					return (tmp_obj->color);
		if (!strncmp(tmp_obj->type,"CONE", 6))
			if (cone_inter(&ray, tmp_obj))
					return (tmp_obj->color);
		if (!strncmp(tmp_obj->type,"CYLINDER", 6))
			if (cylinder_inter(&ray, tmp_obj))
					return (tmp_obj->color);
		object_list = object_list->next;
	}
	return (0);
}

void	ft_trace(t_env *env)
{
	int yc;
	int xc;
	int color;
	t_ray cam;

	cam = env->scene.cam;
	yc = -1;
	while(++yc < env->win_y)
	{
		double yoff = ((1 - (yc / (double)env->win_y)) * 2) - 1;
		xc = -1;
		while(++xc < env->win_x)
		{
			cam.dir.z = -1;
			cam.dir.y = yoff;
			cam.dir.x = ((xc / (double)env->win_x) * 2) - 1;
			vec_norm(&cam.dir);
			color = check_intersection(cam, env->scene.objects);
			ft_px_to_img(&env->img, color, xc, yc);
		}
		ft_img_to_win(env, &env->img);
	}
}

void	startup(t_env *env, int ac, char **av)
{
	env->say = 0;
	env->scene.lightcnt = 0;
	env->scene.objcnt = 0;
	env->scene.objects = NULL;
	env->scene.lights = NULL;
	set_openfd(ac, av, env);
	env->mlx = mlx_init();
	env->win = mlx_new_window(env->mlx, env->win_x, env->win_y, WIN_NAME);
	ft_imginit(env, &env->img, env->win_x, env->win_y);
}

int main(int ac , char **av)
{	
	t_env env;

	startup(&env, ac, av);
	ft_handelhooks(&env);
	ft_trace(&env);
	mlx_loop(env.mlx);
	return (0);
}
