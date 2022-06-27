/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:19:20 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:19:23 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_strrchr(const char *str, int ch)
{
	size_t	len;

	len = ft_strlen(str) + 1;
	while ((len) > 0)
	{
		if (str[len - 1] == (char)ch)
			return ((char *)&str[len - 1]);
		len--;
	}
	return (NULL);
}
