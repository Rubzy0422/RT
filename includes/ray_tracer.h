/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/19 12:51:46 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <libft.h>
# include <libvec.h>

# define BPP		4
# define FILE_HEAD	14
# define INFO_HEAD	40

# define USAGE "Usage:./RT [SCENE FILE] [WINDOW WIDTHxWINDOW HIGHT] [FLAGS]"
# define FLAGS "FLAGS:S:Sound h:Help"
# define WIN_X 1024
# define WIN_Y 768
# define WIN_X_MAX 1980
# define WIN_Y_MAX 1080
# define WIN_NAME "Ray Tracer v1"

typedef struct timeval	t_timeval;
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
	int				win_x;
	int				win_y;
	t_img			img;
	int				say;
}					t_env;

/*
** Image Funcs
*/

void				ft_img_to_win(t_env *env, t_img *img);
void				ft_img_clear(t_img *img, int colo);
void				ft_px_to_img(t_img *img, int colo, int x, int y);
void				ft_imginit(t_env *env, t_img *img, int w, int h);
int					rgb_to_hex(float r, float g, float b);

/*
** IMG SAVE
*/
void				create_bmp(unsigned char *img, int h, int w,
										char *fn);
unsigned char		*infhead(int h, int w);
unsigned char		*file_head(int h, int w);
void				create_bmp(unsigned char *image, int height, int width,
					char*img_file_name);
/*
** MLX_Hooks
*/
void				ft_handelhooks(t_env *env);
int					fdf_exit(void *param);
int					ft_handelkey(int key, void *param);

/*
** Say .. its errors?
*/
void				ft_say(char *str, int bexit, t_env *env);

/*
** Parsing args
*/
void				set_startup(int ac, char **av, t_env *env);
void				load_scene(int fd, t_env *env);
void				ft_win_error_check(int ac, t_env *env);
void				ft_flag_check(char **av, t_env *env, int i);
void				parse_screen_str(char *str, t_env *env);
#endif
