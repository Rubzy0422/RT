/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcsub.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcoetzer <rcoetzer@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/22 19:22:18 by rcoetzer          #+#    #+#             */
/*   Updated: 2019/08/22 19:33:22 by rcoetzer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ray_tracer.h>

char	*ft_strcsub(char const *s, char sc, char ec)
{
	unsigned int	start;
	unsigned int	end;
	unsigned int	len;
	char			*sub;

	start = 0;
	end = 0;

	
	while (s[start] && s[start] != sc)
		start++;
	end += start;
	while (s[end] && s[end] != ec)
		end++;
	len = end - start;
	sub = ft_strsub(s,start + 1,len - 1);
	return (sub);
}