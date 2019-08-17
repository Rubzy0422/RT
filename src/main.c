#include <RT.h>
#include <stdio.h>

int main()
{	
	t_env env;
	int xc;
	int yc;

	xc = -1;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, WIN_NAME);
	ft_imginit(&env, &env.img, WIN_X, WIN_Y);
	
	/*t_vec3 x = set_vec3(1,0,0);
	t_vec3 y = set_vec3(0,1,0);
	t_vec3 z = set_vec3(0,0,-1);
*/
	while(++xc < WIN_X)
	{
		yc = -1;
		while(++yc < WIN_Y) 
		{
			float r = (float)xc / (float)WIN_X;
			float g = (float)yc / (float)WIN_Y;
			float b = 0.2;

			ft_px_to_img(&env.img, rgb_to_hex((255.99*r),(255.99*g),(255.99*b)) ,xc, yc);
		}
	}
	ft_img_to_win(&env, &env.img);
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
}

