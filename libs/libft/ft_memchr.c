/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 23:34:07 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 20:50:19 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	*ft_memchr(const void *arr, int c, size_t n)
{
	while (n > 0)
	{
		if (*(unsigned char *)arr == (unsigned char)c)
			return ((void *)arr);
		arr++;
		n--;
	}
	return (NULL);
}
