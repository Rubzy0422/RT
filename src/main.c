#include <RT.h>


int main()
{
	
	t_env env;

	env.mlx = mlx_init();
	env.win = mlx_new_window(env.mlx, WIN_X, WIN_Y, "RayTracer");
	ft_imginit(&env, &env.img, WIN_X, WIN_Y);
	int nx = WIN_Y;
	int ny = WIN_X;
	for (int j = ny-1; j >= 0; j--) {
		for (int i = 0; i < nx; i++) {
			float r = (float)i / (float)nx;
			float g = (float)j / (float)ny;
			float b = 0.2;
			int ir = (int)(255.99*r);
			int ig = (int)(255.99*g);
			int ib = (int)(255.99*b);

			ft_px_to_img(&env.img, rgb_to_hex(ir, ig, ib) ,j, i);
		}
	}
	ft_img_to_win(&env, &env.img);
	create_bmp((unsigned char *)env.img.raw_data, WIN_Y, WIN_X, "fn.bmp");
	ft_handelhooks(&env);
	mlx_loop(env.mlx);
}

