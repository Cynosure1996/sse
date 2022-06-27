/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:06:09 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:05:59 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strdup(const char *src)
{
	char	*out;
	size_t	len;

	len = ft_strlen(src) + 1;
	out = (char *)malloc(len);
	if (out == 0)
		return (NULL);
	ft_strlcpy(out, src, len);
	return (out);
}
