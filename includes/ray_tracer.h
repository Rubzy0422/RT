/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_tracer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/19 12:51:21 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 12:43:46 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_TRACER_H
# define RAY_TRACER_H

# include <mlx.h>
# include <stdlib.h>
# include <math.h>
# include <stdio.h>
# include <libft.h>

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
# define EROR 1
# define STAT 0
# define DONE 2
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

typedef struct		s_vec3
{	
	float			x;
	float			y;
	float			z;
}					t_vec3;

typedef struct		s_ray
{	
	t_vec3 			origin;
	t_vec3 			dir;
}					t_ray;

typedef struct		s_img
{
	void			*ptr_img;
	int				bpp;
	int				lnsz;
	int				endian;
	char			*raw_data;
	int				w;
	int				h;
	t_vec3			crd;
}					t_img;

typedef struct		s_scene
{
	t_list			*objects;
	t_list			*lights;
	t_ray			cam;
	unsigned int	lightcnt;
	unsigned int	objcnt;
}					t_scene;

typedef struct		s_env
{
	void			*mlx;
	void			*win;
	int				win_x;
	int				win_y;
	t_img			img;
	int				say;
	int				scene_lines;
	t_scene			scene;
}					t_env;

typedef struct		s_light
{
	t_vec3			pos;
	float			strength;
}					t_light;

typedef struct		s_set
{
	int				pos;
	int				radius;
	int				color;
	int				reflection;
	int				normal;
	int				dist;
	int				direction;
	int				angle;
}					t_set;

typedef struct		s_object
{
	char 			*type;
	t_vec3			pos;
	t_vec3			direction;
	float			angle;
	float			radius;
	int				color;
	// int			reflection;
	t_vec3			normal;
	float			dist;
	t_set			set;
}					t_object;


typedef struct		s_sphere
{	
	t_vec3			pos;
	float			radius;
	int				material;
}					t_sphere; 

typedef struct		s_color
{	
	float			red;
	float			green;
	float			blue;
}					t_color;

typedef struct		s_mat
{	
	t_color			diffuse;
	float			reflection;
}					t_mat;


/*
** VEC FUNCS
*/
t_vec3				vec_sub(t_vec3 *v1, t_vec3 *v2);
float				vec_dot(t_vec3 *v1, t_vec3 *v2);
t_vec3				vec_scale(float c, t_vec3 *v);
t_vec3				vec_add(t_vec3 *v1, t_vec3 *v2);
void				vec_norm(t_vec3 *v);

/*
** MATRIX FUNCTIONS
*/

 //STILL DUE

/*
** Image Funcs
*/

void				ft_img_to_win(t_env *env, t_img *img);
void				ft_img_clear(t_img *img, int colo);
void				ft_px_to_img(t_img *img, int colo, int x, int y);
void				ft_imginit(t_env *env, t_img *img, int w, int h);

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
void				set_openfd(int ac, char **av, t_env *env);
int					load_scene(int fd, t_env *env);
void				ft_win_error_check(int ac, t_env *env);
void				ft_flag_check(char **av, t_env *env, int i);
void				parse_screen_str(char *str, t_env *env);

/*
** Parsing Scene
*/
void				scene_parse(int fd, t_env *env);
char				*ft_strcsub(char const *s, char sc, char ec);
t_vec3				ft_vec3parse(char *str, t_env *env);
float				get_float(char *str, t_env *env, int boolean);
int					rgb_to_hex(t_color color);
int					ft_color_parse(char *str, t_env *env);

/*
** checks
*/
void				head_check(t_list *list, t_env *env);
void				obj_checker(t_list *list, t_env *env);
void				reset_set(t_set *set);

void				cam_check(t_list *list, t_env *env);
void				sphere_check(t_list *list, t_env *env);
void				plane_check(t_list *list, t_env *env);
void				light_check(t_list *list, t_env *env);
void				cone_check(t_list *list, t_env *env);
/*
** CREATION
*/
void				light_add(t_vec3 pos, float s, t_env *env);
void				add_object(t_list *new_object, t_env *env);

/*
** USAGE
*/
int					sphere_inter(t_ray *ray, t_object *sphere);
int					plane_inter(t_ray *ray, t_object *plane);
int					cone_inter(t_ray *ray, t_object *cone);
int					cylinder_inter(t_ray *ray, t_object *cylinder);

#endif