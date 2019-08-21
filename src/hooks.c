/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:52:10 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/21 09:22:52 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>
#include <sys/time.h>

char		*create_name(void)
{
	t_timeval	time;
	char		*name;

	gettimeofday(&time, NULL);
	name = ft_strjoin_free(ft_itoa(time.tv_sec), ".bmp", 1, 0);
	return (name);
}

void		ft_handelhooks(t_env *env)
{
	mlx_hook(env->win, 2, 1L << 0, ft_handelkey, env);
	mlx_hook(env->win, 17, 0, fdf_exit, env);
}

int			fdf_exit(void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (env->img.w > 0)
		mlx_destroy_image(env->mlx, env->img.ptr_img);
	mlx_destroy_window(env->mlx, env->win);
	ft_say("Exiting!", 2, env);
	return (0);
}

int			ft_handelkey(int key, void *param)
{
	t_env	*env;
	char	*name;

	env = (t_env *)param;
	if (key == ESC)
		fdf_exit(env);
	if (key == S)
	{
		name = create_name();
		mlx_string_put(env->mlx, env->win, 10, 10, 0xf3f3, "Image saved!");
		ft_say("Image Saved!", 0, env);
		create_bmp((unsigned char *)env->img.raw_data, -env->win_y,
		env->win_x, name);
		free(name);
	}
	return (0);
}
