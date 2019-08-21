/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene_parse.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/21 15:50:37 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/21 15:52:00 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

void	ft_sceneparse(int fd, t_env *env)
{
	char *ln;

	while (get_next_line(fd, &ln))
	{
		ft_putendl(ln);
		free(ln);
	}
	(void)env;
}