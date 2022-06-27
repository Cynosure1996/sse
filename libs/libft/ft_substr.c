/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 19:34:53 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 20:09:02 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*substr;

	if (!s)
		return (NULL);
	if (len == 0 || s[0] == 0)
	{
		substr = (char *)malloc(1);
		if (!substr)
			return (NULL);
		*substr = 0;
		return (substr);
	}
	while (start > 0 && *s)
	{
		s++;
		start--;
	}
	if (ft_strlen(s) < len)
		len = ft_strlen(s);
	substr = (char *)malloc(len + 1);
	if (!substr)
		return (NULL);
	ft_strlcpy(substr, s, len + 1);
	return (substr);
}
