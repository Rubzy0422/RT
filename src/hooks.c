#include <RT.h>

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
	exit(0);
	return (0);
}

int			ft_handelkey(int key, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (key == ESC)
		fdf_exit(env);
	return (0);
}