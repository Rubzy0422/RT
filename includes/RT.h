#ifndef RT_H
#define RT_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <libft.h>
# include <libvec.h>

# define BPP		4
# define FILE_HEAD	14
# define INFO_HEAD	40

# define WIN_X 1920
# define WIN_Y 1080
# define WIN_NAME "Ray Tracer v1"

typedef struct tm	*t_timeinfo;

/* 
** Key DEFINES
*/

# if __APPLE__
#  define ESC		53
#  define S			1
# elif __linux__
#  define ESC		0xff1b
#  define S			's'
# endif

/*
**Structs
*/

typedef struct		s_img
{
	void			*ptr_img;
	int				bpp;
	int				lnsz;
	int				endian;
	char			*raw_data;
	int				w;
	int				h;
	t_vec2			crd;
}					t_img;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	t_img			img;
}					t_env;

/*
** Image Funcs
*/

void	ft_img_to_win(t_env *env, t_img *img);
void	ft_img_clear(t_img *img, int colo);
void	ft_px_to_img(t_img *img, int colo, int x, int y);
void	ft_imginit(t_env *env, t_img *img, int w, int h);
int		rgb_to_hex(float r, float g, float b);

/*
** IMG SAVE
*/
void			create_bmp(unsigned char *img, int h, int w,
										char *fn);
unsigned char	*infhead(int h, int w);
unsigned char	*file_head(int h, int w);
void			create_bmp(unsigned char *image, int height, int width, char* imageFileName);

/*
** MLX_Hooks
*/
void		ft_handelhooks(t_env *env);
int			fdf_exit(void *param);
int			ft_handelkey(int key, void *param);
#endif 