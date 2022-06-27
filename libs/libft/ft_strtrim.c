/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/19 22:26:46 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:17:52 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

static size_t	ft_find_pos(char const *str, char const *set, size_t pos)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = pos;
	while (set[i])
	{
		if (set[i] == str[j] && str[j])
		{
			if (pos == 0)
				j++;
			else
				j--;
			i = 0;
			continue ;
		}
		i++;
	}
	return (j);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	size_t	start;
	size_t	end;

	if (!s1)
		return (ft_strdup(""));
	if (!set)
		return (ft_strdup(s1));
	end = ft_strlen(s1);
	start = ft_find_pos(s1, set, 0);
	if (!s1[start])
		end = 0;
	else
		end = ft_find_pos(s1, set, end - 1);
	return (ft_substr(s1, start, (end - start + 1)));
}
