#include <RT.h>
#include <stdio.h>


int main(int ac , char **av)
{	
	t_env env;
	int xc;
	int yc;

	env.say = 0;
	set_startup(ac, av, &env);
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, env.win_x, env.win_y, WIN_NAME);
	ft_imginit(&env, &env.img, env.win_x, env.win_y);
	
	t_cam cam;
	VEC(cam.pos, 3, 1.5, -4);

//	t_vec3 x = set_vec3(1,0,0);
	t_vec3 y = set_vec3(0,1,0);
//	t_vec3 z = set_vec3(0,0,-1);

	t_vec3 lookat = set_vec3(0,0,0);
	t_vec3 diff_btw = (vec3_min(cam.pos, lookat));
	
	cam.dir = vec3_norm(vec3_neg(diff_btw));
	cam.right = vec3_norm(vec_cross(y, cam.dir));
	cam.down = vec3_norm(vec_cross(cam.right, cam.dir));
//	t_color White_light;
	//t_color pretty_green;
	//t_color gray;
	//t_color black;
	//COLOR(black,0,0,0,0);
	//COLOR(pretty_green, 0.5, 1.0, 0.5, 0.3);
//	COLOR(gray, 0.5, 0.5, 0.5, 0);
//	COLOR(black, 0.0, 0.0, 0.0,0);
//	COLOR(White_light, 1, 1, 1, 0);

//	t_vec3 light_pos = set_vec3(-7, 10,-10);
//	t_light scene_light = set_light(light_pos, White_light);
	
	xc = -1;
	while(++xc < env.win_x)
	{
		yc = -1;
		while(++yc < env.win_y) 
		{			
			ft_px_to_img(&env.img, /*(hex)*/ 0xffffff,xc, yc);
		}
	}
	ft_img_to_win(&env, &env.img);
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
}

