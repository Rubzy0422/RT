/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   log.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/18 11:26:42 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/21 15:54:02 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void		ft_status(char *str)
{
	ft_putstr("\e[33m[STATUS]\t\t");
	ft_putstr(str);
	ft_putstr("\e[39m\n");
}

void		ft_errorprmp(char *str)
{
	ft_putstr("\e[31m[ERROR]\t\t");
	ft_putstr(str);
	ft_putstr("\e[39m\n");
	exit(-1);
}

void		ft_proccomplete(char *str)
{
	ft_putstr("\e[32m[DONE]\t\t\t");
	ft_putstr(str);
	ft_putstr("\e[39m\n");
	exit(0);
}

void		ft_say(char *str, int bexit, t_env *env)
{
	char *cmd;

	if (env->say == 1)
	{
		cmd = ft_strjoin("say ", str);
		system(cmd);
		free(cmd);
	}
	if (bexit == 0)
		ft_status(str);
	else if (bexit == 1)
		ft_errorprmp(str);
	else if (bexit == 2)
		ft_proccomplete(str);
}
