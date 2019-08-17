#include <RT.h>
#include <stdio.h>

int main()
{	
	t_env env;
	int xc;
	int yc;

	xc = -1;
	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "RayTracer");
	ft_imginit(&env, &env.img, WIN_X, WIN_Y);
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

