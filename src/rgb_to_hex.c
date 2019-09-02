/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rgb_to_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/27 08:41:30 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/28 09:28:19 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

int		rgb_to_hex(t_color color)
{
	int ret;

	ret = color.red;
	ret *= 0x100;
	ret += color.green;
	ret *= 0x100;
	ret += color.blue;
	return (ret);
}