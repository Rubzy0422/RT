/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 13:00:12 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/20 20:10:58 by rcoetzer         ###   ########.fr       */
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
	set_startup(ac, av, &env);
	//float aspect = (float)env.win_x / (float)env.win_y;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_x, env.win_y, WIN_NAME);
	ft_imginit(&env, &env.img, env.win_x, env.win_y);
	
// 	t_cam cam;
// 	VEC(cam.pos, 3, 1.5, -4);

// //	t_vec3 x = set_vec3(1,0,0);
// 	t_vec3 y = set_vec3(0,1,0);
// //	t_vec3 z = set_vec3(0,0,-1);

// 	t_vec3 lookat = set_vec3(0,0,0);
// 	t_vec3 diff_btw = (vec3_min(cam.pos, lookat));
	
// 	cam.dir = vec3_norm(vec3_neg(diff_btw));
// 	cam.right = vec3_norm(vec_cross(y, cam.dir));
// 	cam.down = vec3_norm(vec_cross(cam.right, cam.dir));
// //	t_vec3 light_pos = set_vec3(-7, 10,-10);
// //	t_light scene_light = set_light(light_pos, White_light);
// 	t_sphere sphere;
// 	t_color maroon;
// 	maroon.red = 0.5;
// 	maroon.green = 0.25;
// 	maroon.blue = 0.25; 
// 	maroon.special = 0;
// 	sphere = def_sphere();
	
// 	t_plane plane = set_plane(y, -1, maroon);
// 	double xamnt, yamnt;
	xc = -1;
	while(++xc < env.win_x)
	{
		// if (env.win_x > env.win_y)
		// {
		// 	xamnt = ((xc+0.5)/ env.win_x) * aspect - (env.win_x-env.win_y)/env.win_y/2;
		// 	yamnt = ((env.win_y - yc) + 0.5 / env.win_y);
		// }
		// else if (env.win_y > env.win_x)
		// {
		// 	xamnt = (xc + 0.5)/env.win_x;
		// 	yamnt = (((env.win_y -yc) + 0.5)/env.win_y)/aspect - (((env.win_y-env.win_x)/(float)env.win_x)/2);
		// }
		/*
		*/
	
		// else
		// {
			// xamnt =(xc + 0.5)/env.win_x;
			// yamnt = (env.win_y -yc + 0.5)/env.win_y;
		// }

		//Create rays
	//	t_vec3	cam_ray_or;
	//	cam_ray_or = cam.pos;
	//	t_vec3	cam_raydir;
	////	camdir.vecadd(camright.vectMult(xamnt - 0.5).vectAdd(camdown.vectMult(yamnt - 0.5))).normalize();
		//vec3_add(cam.dir
		//t_ray cam_ray(cam_ray_or, cam_raydir);
		//list of intersections
		//list of objects;
	//	for (int i = 0; i < scene_objectslen; i++)
	//	{
			//loop through object find intersection to camray
	//		intersections.push_back(scene_objects.at(i)->findintersection(cam_ray))
	//	}
		yc = -1;
		while(++yc < env.win_y) 
		{			
			ft_px_to_img(&env.img, 0xff, xc, yc);
		}
	}
	ft_img_to_win(&env, &env.img);
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
}
