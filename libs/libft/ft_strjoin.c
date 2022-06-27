/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 21:31:37 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:07:51 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"
#include<stdio.h>

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len_str;
	char	*str;

	if (!s1 || !s2)
		return (ft_strdup(""));
	len_str = ft_strlen(s1) + ft_strlen(s2);
	str = malloc(sizeof(const char) * len_str + 1);
	if (!str)
		return (NULL);
	while (*s1)
	{
		*str = *s1;
		s1++;
		str++;
	}
	while (*s2)
	{
		*str = *s2;
		s2++;
		str++;
	}
	*str = 0;
	str -= (len_str);
	return (str);
}
