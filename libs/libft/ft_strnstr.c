/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/22 21:18:47 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 21:18:51 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i_b;
	size_t	i_l;	

	i_b = 0;
	i_l = 0;
	if (!little[0])
		return ((char *)big);
	while (big[i_b + i_l] && (i_b + i_l) < len)
	{
		if (big[i_b + i_l] == little[i_l])
			i_l++;
		if (!little[i_l])
			return ((char *)&big[i_b]);
		if (big[i_b + i_l] != little[i_l])
		{
			i_l = 0;
			i_b++;
		}
	}
	return (NULL);
}
