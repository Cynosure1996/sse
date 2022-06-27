/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:46:11 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:19:06 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (!n)
		return (0);
	i = 0;
	while ((((unsigned char *)s1)[i]) &&
			(((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]) &&
			(n > (i + 1)))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
