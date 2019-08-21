/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:12 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/21 15:29:37 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>
#include <stdio.h>

int main(int ac , char **av)
{	
	t_env env;
	int xc;
	int yc;

	env.say = 0;
	// read file into env->scene
	set_startup(ac, av, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_x, env.win_y, WIN_NAME);
	ft_imginit(&env, &env.img, env.win_x, env.win_y);

	xc = -1;
	while(++xc < env.win_x)
	{
		yc = -1;
		while(++yc < env.win_y) 
		{			
			ft_px_to_img(&env.img, 0xffffff, xc, yc);
		}
	}
	ft_img_to_win(&env, &env.img);
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
}
