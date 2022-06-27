/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fchrysta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/18 22:29:19 by fchrysta          #+#    #+#             */
/*   Updated: 2021/10/22 20:46:26 by fchrysta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t num, size_t size)
{
	size_t	i;
	void	*ptr;

	i = 0;
	ptr = malloc(size * num);
	if (!ptr)
		return (NULL);
	while (i < (num * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
