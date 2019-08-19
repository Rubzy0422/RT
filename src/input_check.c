/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 19:20:55 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/18 19:21:05 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <RT.h>

void	parse_screen_str(char *str, t_env *env)
{
	char **split;
	char *str1;

	if (ft_instr(str, 'x') && ft_instr(str, ']'))
	{
		split = ft_strsplit(str, 'x');
		str1 = ft_strsub(split[0], 1, ft_strlen(split[0]) - 1);
		env->win_x = ft_atoi(str1);
		env->win_y = ft_atoi(split[1]);
		ft_freearr(split);
		free(str1);
	}
}

void	ft_flag_check(char **av, t_env *env, int i)
{
	if (av[i][0] == '-' && av[i][1] == 'h')
	{
		ft_say(USAGE, 0, env);
		ft_say(FLAGS, 0, env);
		exit(0);
	}
	if (av[i][0] == '-' && av[i][1] == 'S')
		env->say = 1;
	if (av[i][0] == '[')
		parse_screen_str(av[i], env);
}

void	ft_win_error_check(int ac, t_env *env)
{
	if (!env->win_x || env->win_x < 100 || env->win_y < 100)
	{
		if (ac > 1 && ac < 5)
			ft_say("Screen not set or invalid", 0, env);
		if (ac > 5)
			ft_say("Too many arguments given",0,env);
		ft_say("Setting to default Resolution", 0, env);
		env->win_x = WIN_X;
		env->win_y = WIN_Y;
	}
	if (env->win_x > WIN_X_MAX || env->win_y > WIN_Y_MAX)
	{
		ft_say("Input too large!",0,env);
		ft_say("Setting to default Resolution", 0, env);
		env->win_x = WIN_X;
		env->win_y = WIN_Y;
	}
}

void	load_scene(int fd, t_env *env)
{
	char *ln;
	while (get_next_line(fd,&ln) > 0)
	{
		ft_putstr("SCENE:");
		ft_putstr(ln);
		ft_putchar('\n');
		free(ln);
	}
	(void)env;
}

void	set_startup(int ac, char **av, t_env *env)
{
	int fd;
	int i;
	int scene_cnt;

	i = 1;
	scene_cnt = 0;
	if (ac < 2)
		ft_say(USAGE, 1, env);
	while (i < ac)
	{
		ft_flag_check(av, env, i);		
		if (ft_strequ(ft_strrchr(av[i], '.'), ".scene") > 0)
		{
			if (scene_cnt == 0)
				fd = open(av[i], O_RDONLY);
			scene_cnt++;
		}
		if (scene_cnt > 1)
			ft_say("Only one Scene file Allowed!", 1, env);
		i++;
	}
	ft_win_error_check(ac, env);
	if (fd <= 0)
		ft_say("No Valid Scene file entered!", 1, env);
	load_scene(fd, env);
}