#include <RT.h>
#include <sys/time.h>



char		*create_name()
{
	time_t	rawtime;
	char	*name;
	time ( &rawtime );
	t_timeinfo = localtime ( &rawtime );
	
	name = ft_strjoin(asctime(t_timeinfo),".bmp");
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
	exit(0);
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
			create_bmp((unsigned char *)env->img.raw_data, -WIN_Y, WIN_X, name);
			free(name);
		}
	return (0);
}